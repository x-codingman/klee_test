#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    TX_BYTE_POOL * pool_ptr;
    klee_make_symbolic_controllable(&pool_ptr, sizeof(pool_ptr), "pool_ptr", true);
    VOID ** memory_ptr;
    klee_make_symbolic_controllable(&memory_ptr, sizeof(memory_ptr), "memory_ptr", true);
    ULONG memory_size;
    klee_make_symbolic_controllable(&memory_size, sizeof(memory_size), "memory_size", true);
    ULONG wait_option;
    klee_make_symbolic_controllable(&wait_option, sizeof(wait_option), "wait_option", true);
    m_txe_byte_allocate(pool_ptr, memory_ptr, memory_size, wait_option);
}
