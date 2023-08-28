- //注释 /home/klee/threadx/threadx/common/inc/tx_api.h 128行，“#include "tx_port.h"”, 不考虑架构相关代码。
- 注释 /home/klee/threadx/threadx/common/src/tx_initialize_kernel_enter.c 117，121行，忽略架构相关代码。
- 注释 /home/klee/threadx/threadx/common/src/tx_thread_create.c 225行，忽略thread的stack初始化，
- 注释 /home/klee/threadx/threadx/ports/cortex_m33/gnu/inc/tx_port.h 628，629行，忽略架构底层汇编指令
- 在klee_help.h中增加_tx_thread_secure_stack_allocate、_tx_thread_schedule的弱定义。





### 编译问题
- 编译后发现运行程序，在klee::Executor::initializeGlobals处报Segmentation fault (core dumped)，后面调试发现是由于threadx中定义了函数指针，KLEE在load函数指针的时候报错。
- 上述问题解决，是由于对global function pointer 的初始化错误所导致。因为我们会对所有的全局指针进行内存分配，然后全局变量初始化过程中未考虑函数指针类型的的全局变量。

- 在编译过程中 _txe_event_flags_create': symbol multiply defined