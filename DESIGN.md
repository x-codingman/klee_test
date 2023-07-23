# DESIGN

## 检测机制

检测机制，以任意写为例：遇到符号指针解引用操作时，如C语言中*a=b，首先检查a与b是否都是攻击者可控制的符号值，若是，再检查a是否能指向攻击者定义的危险区域，如(if MPU_REGISITER_START < a && a< MPU_REGISITER_END), 若是，则该位置存在问题。

注意，目前检测机制针对的是API在实现上存在问题，暂不能检测功能上存在问题的API。对于功能上存在问题的API，攻击者一般不能操纵其参数来完成危险操作，但API本身会完成危险操作。例如MPU_ENABLE()这一类的函数。对这一类函数，后期可以再具体分析。

## 关于地址对应关系

#### 问题1：是否一定需要地址之间的对应关系？即KLEE运行环境的地址空间和真实程序的地址空间的映射关系。

**目前结论：不需要**

**分析:**

(global variable)

针对程序运行过程中的符号指针X，考虑以下两种情况：

1. 如果对符号指针X，不存在地址范围约束，那么X可以指向全域，意味着攻击者可以控制该指针指向任意内存，因此，不需要对其进行约束。

2. 如果对符号指针X，存在地址范围约束，比如针对X存在如下约束：MPU_REGION_0_START<=X<=MPU_REGION_0_END。那么在对X进行内存分配的时候，其分配的地址必须符合该约束要求。此时，若没有地址之间的对应关系，为X分配的memory object的地址（KLEE中的地址空间）需要满足该约束要求（真实的地址空间）才能保证程序的正常运行。我们根据攻击者的能力（即攻击者在真实地址范围的控制能力，比如整个用户空间的地址范围等，对于攻击者的能力，需要提前输入一个攻击者的能力范围给KLEE以便对此进行判断）存在以下两种情况：

​    （1）这个地址范围可以被攻击者控制，那么对其值进行具体化，分配一块用于辅助检测符号化的memory object给它。注意，该分配地址可以不满足该约束，这是因为攻击者可以控制这块内存区域，意味着该地址范围的约束内，攻击者可以任意构造内存块（对应符号化的memory object）。

​    （2）这个地址范围不能被攻击者所控制，那么对该地址范围内进行memory object的resolve。但在under constrained的情况下，我们无法获得MPU_REGION_0_START这些值，因为这些值在链接阶段才能确定。因此，为解决这个问题，我们也对其进行分配一块用于辅助程序运行的符号化的内存，但该符号化的内存的目的是为了程序的运行。为了将其与前面的符号内存区分，可以对该符号内存设置标志位。

---

#### 问题2: 如果没有地址对应关系，那么在KLEE运行环境中如何生成test case以提供一个真实的利用场景？

分析：

根据利用的情况我们分为两种情况，一种是API的参数可以直接触发漏洞，另一种是攻击者需要构造参数所指向的内存块，然后间接的触发漏洞。

对于第一种情况，我们生成的test case直接输出该参数。

对于第二种情况，我们最终生成的test case是所有分配的辅助检测的符号化memory object的一个snapshot,其中存在一个漏洞指针是可以完成漏洞利用的。由于这些memory object都是在攻击者控制的范围之内，攻击者可以在其可控制的内存中构造出相同的memory object以及对应的漏洞指针，是其指向对应的区域，完成对漏洞的利用。

## Case Study

该API存在越权任意写漏洞，攻击者可以通过构造内存块完成对任意内存的写操作。

```c
privileged_api（ANYTYPE *input1，ANYTYPE *input2）
{
  Char b = input2->b;
	Struct c = input1->c;
	Char * bomb = c->a;
  if(c->d == 0)
		*bomb = b;                   // Vulnerability 
	return;
}
```

第七行是一个任意写的漏洞，我们发现该漏洞以后，KLEE会生成test case。具体来说，它会根据a和b生成其父结构体的memory object的内容，如此回溯直至到达测试api的参数，即input1与input2。最终生成的test case是如下图所示的一个树状结构。攻击者需要构造input1，满足其子成员变量d为0，子成员变量a为其想要改写的地址，b为其想要改写的值。

```mermaid
graph BT
I1((input1))
I2((input2))
A((a))
B((b))
C((c))
D((d=0))
E((e))
C-->I1
A-->C
D-->C
B-->I2
E-->I2
```

#### Test case generation 

```json
[
  {
    "name": "input1",
    "size": 8,
    "address": 0xcad,
    "data": 0xc
	},
	{
    "name": "c",
    "size": 16,
    "address": 0xc,
    "data": b'0x0000000a000000000
  }
]
```

<div style="page-break-after: always;"></div>

### DESIGN



![method-v2](./DESIGN.assets/method-v2.png)

<div style="page-break-after: always;"></div>

### System Architecture



![method-v3](./DESIGN.assets/method-v3.png)

<div style="page-break-after: always;"></div>

### Memory model



![attacker-based-memory-object-resolving](./DESIGN.assets/attacker-based-memory-object-resolving.png)