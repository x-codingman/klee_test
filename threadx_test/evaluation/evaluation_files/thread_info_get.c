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
    CHAR ** name;
    klee_make_symbolic_controllable(&name, sizeof(name), "name", true);
    UINT * state;
    klee_make_symbolic_controllable(&state, sizeof(state), "state", true);
    ULONG * run_count;
    klee_make_symbolic_controllable(&run_count, sizeof(run_count), "run_count", true);
    UINT * priority;
    klee_make_symbolic_controllable(&priority, sizeof(priority), "priority", true);
    UINT * preemption_threshold;
    klee_make_symbolic_controllable(&preemption_threshold, sizeof(preemption_threshold), "preemption_threshold", true);
    ULONG * time_slice;
    klee_make_symbolic_controllable(&time_slice, sizeof(time_slice), "time_slice", true);
    TX_THREAD ** next_thread;
    klee_make_symbolic_controllable(&next_thread, sizeof(next_thread), "next_thread", true);
    TX_THREAD ** next_suspended_thread;
    klee_make_symbolic_controllable(&next_suspended_thread, sizeof(next_suspended_thread), "next_suspended_thread", true);
    m_txe_thread_info_get(thread_ptr, name, state, run_count, priority, preemption_threshold, time_slice, next_thread, next_suspended_thread);
}
