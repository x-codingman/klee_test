#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

UCHAR                   pool_start[9120];

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_EVENT_FLAGS_GROUP * group_ptr;
    klee_make_symbolic_controllable(&group_ptr, sizeof(group_ptr), "group_ptr", true);
    ULONG flags_to_set;
    klee_make_symbolic_controllable(&flags_to_set, sizeof(flags_to_set), "flags_to_set", true);
    UINT set_option;
    klee_make_symbolic_controllable(&set_option, sizeof(set_option), "set_option", true);
    m_txe_event_flags_set(group_ptr, flags_to_set, set_option);
}
