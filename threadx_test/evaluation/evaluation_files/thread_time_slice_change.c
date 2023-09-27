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
    ULONG new_time_slice;
    klee_make_symbolic_controllable(&new_time_slice, sizeof(new_time_slice), "new_time_slice", true);
    ULONG * old_time_slice;
    klee_make_symbolic_controllable(&old_time_slice, sizeof(old_time_slice), "old_time_slice", true);
    m_txe_thread_time_slice_change(thread_ptr, new_time_slice, old_time_slice);
}
