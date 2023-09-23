#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    TX_QUEUE * queue_ptr;
    klee_make_symbolic_controllable(&queue_ptr, sizeof(queue_ptr), "queue_ptr", true);
    CHAR ** name;
    klee_make_symbolic_controllable(&name, sizeof(name), "name", true);
    ULONG * enqueued;
    klee_make_symbolic_controllable(&enqueued, sizeof(enqueued), "enqueued", true);
    ULONG * available_storage;
    klee_make_symbolic_controllable(&available_storage, sizeof(available_storage), "available_storage", true);
    TX_THREAD ** first_suspended;
    klee_make_symbolic_controllable(&first_suspended, sizeof(first_suspended), "first_suspended", true);
    ULONG * suspended_count;
    klee_make_symbolic_controllable(&suspended_count, sizeof(suspended_count), "suspended_count", true);
    TX_QUEUE ** next_queue;
    klee_make_symbolic_controllable(&next_queue, sizeof(next_queue), "next_queue", true);
    m_txe_queue_info_get(queue_ptr, name, enqueued, available_storage, first_suspended, suspended_count, next_queue);
}
