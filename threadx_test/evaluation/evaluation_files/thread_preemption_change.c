#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_THREAD * thread_ptr;
    klee_make_symbolic_controllable(&thread_ptr, sizeof(thread_ptr), "thread_ptr", true);
    UINT new_threshold;
    klee_make_symbolic_controllable(&new_threshold, sizeof(new_threshold), "new_threshold", true);
    UINT * old_threshold;
    klee_make_symbolic_controllable(&old_threshold, sizeof(old_threshold), "old_threshold", true);
    m_txe_thread_preemption_change(thread_ptr, new_threshold, old_threshold);
}
