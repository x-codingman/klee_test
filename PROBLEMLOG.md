# Problemlog

## [3.3.0]
- 因为对符号指针load时就分配绑定，导致符号指针在程序分支判断时就具有具体值，从而无法覆盖一些由符号指针决定的程序分支，比如symbolic pointer == NULL、symbolic pointer1 > symbolic pointer2 [x]
- 因为对全局变量也做符号化处理，当前漏洞检测机制没有对address区分出是全局变量的符号指针，从而漏洞位置里会出现误报（false positive）[x]
- 当前漏洞检测机制只支持检测写64位0，不支持更细粒度的值写入，比如第0位为0 [ ]
- 对于包含符号变量的运算再赋值给符号变量可能存在误报，比如pxTimer->ucStatus &= ( ( uint8_t ) 0xfb );pxTimer是一个符号指针，如果pxTimer->ucStatus想被赋值为0，它本来的值只能是0或4 [ ]

## [3.4.0]
- 先create再测试的方式有影响一些API的分支覆盖 [ ]

## [3.5.1]
- 不能处理symbolic pointer + symbolic index的表达式[ ]
- 没有解决void类型、uint8_t类型、char类型指针的内存分配大小问题[ ]
- 漏洞检测机制没有考虑保证函数正常退出，从而漏洞位置里会出现误报（false positive）[ ]

