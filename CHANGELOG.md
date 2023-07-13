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