#ifndef KLEE_HELP_H
    #define KLEE_HELP_H
 
    #include "stdbool.h"
    #include <stdint.h>
    #include "tx_port.h"

    UINT  __attribute__((weak))  _tx_thread_secure_stack_allocate(struct TX_THREAD_STRUCT *tx_thread, ULONG stack_size){}
    VOID  __attribute__((weak))      _tx_thread_schedule(VOID){}



 
    




#endif