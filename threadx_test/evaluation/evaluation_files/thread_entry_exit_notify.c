#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    TX_THREAD * thread_ptr;
    klee_make_symbolic_controllable(&thread_ptr, sizeof(thread_ptr), "thread_ptr", true);
    VOID (*thread_entry_exit_notify)(TX_THREAD *notify_thread_ptr, UINT type);
    klee_make_symbolic_controllable(&thread_entry_exit_notify, sizeof(thread_entry_exit_notify), "thread_entry_exit_notify", true);
    m_txe_thread_entry_exit_notify(thread_ptr, thread_entry_exit_notify);
}
