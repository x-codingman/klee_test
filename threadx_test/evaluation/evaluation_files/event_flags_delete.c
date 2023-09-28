#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_EVENT_FLAGS_GROUP * group_ptr;
    klee_make_symbolic_controllable(&group_ptr, sizeof(group_ptr), "group_ptr", true);
    m_txe_event_flags_delete(group_ptr);
}
