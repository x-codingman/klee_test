#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_TIMER * timer_ptr;
    klee_make_symbolic_controllable(&timer_ptr, sizeof(timer_ptr), "timer_ptr", true);
    ULONG initial_ticks;
    klee_make_symbolic_controllable(&initial_ticks, sizeof(initial_ticks), "initial_ticks", true);
    ULONG reschedule_ticks;
    klee_make_symbolic_controllable(&reschedule_ticks, sizeof(reschedule_ticks), "reschedule_ticks", true);
    m_txe_timer_change(timer_ptr, initial_ticks, reschedule_ticks);
}
