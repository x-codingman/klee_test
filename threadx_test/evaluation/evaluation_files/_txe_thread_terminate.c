#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    TX_THREAD * thread_ptr;
    klee_make_symbolic_controllable(&thread_ptr, sizeof(thread_ptr), "thread_ptr", true);
    m_txe_thread_terminate(thread_ptr);
}
