# FreeRTOS中修改的文件

- 注释 tasks.c 997 line, 避免调用external function pthread_once等。6/22
- 注释task.c 3062行, 避免对pxCurrentTCB重复赋值。6/22