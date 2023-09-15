#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    TX_THREAD * thread_ptr;
    klee_make_symbolic_controllable(&thread_ptr, sizeof(thread_ptr), "thread_ptr", true);
    UINT new_threshold;
    klee_make_symbolic_controllable(&new_threshold, sizeof(new_threshold), "new_threshold", true);
    UINT * old_threshold;
    klee_make_symbolic_controllable(&old_threshold, sizeof(old_threshold), "old_threshold", true);
    mthread_preemption_change(thread_ptr, new_threshold, old_threshold);
}
