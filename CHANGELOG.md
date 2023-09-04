# Changelog

## [3.4.0] - 2023-06-29
### Changed
- 修改了内存分配的时机。在遇到符号指针的时候对其进行memory object的分配，并对其进行记录。在对符号指针进行解引用的时候进行符号指针以及memory object的绑定。
— 修改符号指针与memory object的绑定模式。符号指针与内存分配后的memory object使用约束的方式进行绑定（之前是地址写回的方式）。

## [3.5.1] - 2023-07-11 - 2023-07-13
- 在state中增加真实地址空间的范围约束constraintsForTargetApp, 用于记录目标程序在运行中的地址范围约束,
该地址范围约束与KLEE程序中的约束区分开。
- 为每一个MO记录其是否可控的信息mo_controllable_info，在ROP场景下表示该MO能否被攻击者构造，该属性首先继承其父结构体的属性，然后结合目标程序的范围约束确定最终值。
- 在fork的时候检查当前的condition是否和符号指针有关，如果有关，则忽略改条约束，并将改约束加入
- 增加函数isControllableAddress用来判断该符号指针指向的MO是否可控。用于在解引用时判断该MO是否可控。
- 更新发现vulnerability的输出内容，输出address以及value的值。
- 更新检查机制,对地址范围进行判断，对MO的可控属性进行判断。
- 更新对global变量的MO初始化，暂把所有global变量设置为不可控。

## [3.5.2] - 2023-7-18 - 2023-7-20
- 增加mo_controllable_info的初始化。
- 增加klee_make_symbolic_controllable函数
- 修复load阶段多次分配mo的问题，导致controllable flag无法有效传播。
- 修改mo_controllable_info的初始化，之前修改有误。
- 增加findMemoryObject，用于根据一个具体值找到其对应的MO。
- 修改isControllableAddress，cover 存在address被具体化后的情况。


## [3.5.3] - 2023-7-21 - 2023-7.23
- 在做address的binding时，增加对address的简化操作，保证在地址在传播时的一致性。
- 增加pointer_of_mo_controllable_info，用于记录分配当前mo的指针的可控信息。
- 在检查机制中，通过判断address所在mo的可控信息以判断当前address是否可控。
- 在检查机制中，增加对address的判断。
- TODO，通过具体值得到符号表达式暂未考虑offset。
- 修改main.c中的MPU范围，之前范围不够准确，导致一些漏洞未发现。
- 优化解引用机制，增加getAddKids函数用于得到原ADD类型表达式的所有子表达式，并用所有子表达式去匹配之前load阶段分配的内存的表达式。
- 优化检测机制，将检测粒度优化至bit位。


## [3.5.3] - 2023-7-29 - 2023-8-1
- 解决全局函数指针初始化问题，会导致KLEE程序崩溃，解决办法是在对全局变量进行lazy initialization时对函数指针进行特殊情况处理。
- 在fork时将constraints信息一并加入addressConstraintsForTargetApp中，保证在vulnerability detection的时候对考虑到所有的限制。
- 修复evalution tool，之前其中的”true“和”false“为字符串类型，修改为bool类型，并且将“restricted”类型的变量设置为“true”，即controllable。
- 更新evaluation tool，可以将函数的信息统一放在funcs.json中，然后生成每个函数的测试c文件。

## [3.5.4] - 2023-8-11
- 更新evaluate tool

## [3.5.4] - 2023-8-19
- 取消对global variable指针的初始化

## [表达式替换] - 2023-9-4
- 在3.5.4的基础上对含有lazy initialization具体指针值的约束进行符号化还原