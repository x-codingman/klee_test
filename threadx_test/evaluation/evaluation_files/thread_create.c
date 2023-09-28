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
    CHAR * name_ptr;
    klee_make_symbolic_controllable(&name_ptr, sizeof(name_ptr), "name_ptr", true);
    VOID (*entry_function)(ULONG entry_input);
    klee_make_symbolic_controllable(&entry_function, sizeof(entry_function), "entry_function", true);
    ULONG entry_input;
    klee_make_symbolic_controllable(&entry_input, sizeof(entry_input), "entry_input", true);
    VOID * stack_start;
    klee_make_symbolic_controllable(&stack_start, sizeof(stack_start), "stack_start", true);
    ULONG stack_size;
    klee_make_symbolic_controllable(&stack_size, sizeof(stack_size), "stack_size", true);
    UINT priority;
    klee_make_symbolic_controllable(&priority, sizeof(priority), "priority", true);
    UINT preempt_threshold;
    klee_make_symbolic_controllable(&preempt_threshold, sizeof(preempt_threshold), "preempt_threshold", true);
    ULONG time_slice;
    klee_make_symbolic_controllable(&time_slice, sizeof(time_slice), "time_slice", true);
    UINT auto_start;
    klee_make_symbolic_controllable(&auto_start, sizeof(auto_start), "auto_start", true);
    UINT thread_control_block_size;
    klee_make_symbolic_controllable(&thread_control_block_size, sizeof(thread_control_block_size), "thread_control_block_size", true);
    m_txe_thread_create(thread_ptr, name_ptr, entry_function, entry_input, stack_start, stack_size, priority, preempt_threshold, time_slice, auto_start, thread_control_block_size);
}
