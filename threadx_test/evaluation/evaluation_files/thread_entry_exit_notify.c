#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    TX_THREAD * thread_ptr;
    klee_make_symbolic_controllable(&thread_ptr, sizeof(thread_ptr), "thread_ptr", true);
    VOID (*thread_entry_exit_notify)(TX_THREAD *notify_thread_ptr, UINT type);
    klee_make_symbolic_controllable(&thread_entry_exit_notify, sizeof(thread_entry_exit_notify), "thread_entry_exit_notify", true);
    mthread_entry_exit_notify(thread_ptr, thread_entry_exit_notify);
}
