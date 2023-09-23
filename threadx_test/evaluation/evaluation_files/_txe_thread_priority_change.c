#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    TX_THREAD * thread_ptr;
    klee_make_symbolic_controllable(&thread_ptr, sizeof(thread_ptr), "thread_ptr", true);
    UINT new_priority;
    klee_make_symbolic_controllable(&new_priority, sizeof(new_priority), "new_priority", true);
    UINT * old_priority;
    klee_make_symbolic_controllable(&old_priority, sizeof(old_priority), "old_priority", true);
    m_txe_thread_priority_change(thread_ptr, new_priority, old_priority);
}
