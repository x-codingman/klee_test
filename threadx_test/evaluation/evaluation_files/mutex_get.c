#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_MUTEX * mutex_ptr;
    klee_make_symbolic_controllable(&mutex_ptr, sizeof(mutex_ptr), "mutex_ptr", true);
    ULONG wait_option;
    klee_make_symbolic_controllable(&wait_option, sizeof(wait_option), "wait_option", true);
    m_txe_mutex_get(mutex_ptr, wait_option);
}
