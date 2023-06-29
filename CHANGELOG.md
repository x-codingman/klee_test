# Changelog

## [1.0.0] - 2023-06-29
### Changed
- 修改了内存分配的时机。在遇到符号指针的时候对其进行memory object的分配，并对其进行记录。在对符号指针进行解引用的时候进行符号指针以及memory object的绑定。
— 修改符号指针与memory object的绑定模式。符号指针与内存分配后的memory object使用约束的方式进行绑定（之前是地址写回的方式）。
