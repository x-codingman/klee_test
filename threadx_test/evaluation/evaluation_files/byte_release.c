#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    VOID * memory_ptr;
    klee_make_symbolic_controllable(&memory_ptr, sizeof(memory_ptr), "memory_ptr", true);
    m_txe_byte_release(memory_ptr);
}
