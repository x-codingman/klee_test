#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;
extern TX_THREAD *    _tx_thread_execute_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    klee_make_symbolic_controllable(&_tx_thread_execute_ptr, sizeof(_tx_thread_execute_ptr), "_tx_thread_execute_ptr", false);

    mthread_relinquish();
}
