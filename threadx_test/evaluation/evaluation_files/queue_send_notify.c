#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    TX_QUEUE * queue_ptr;
    klee_make_symbolic_controllable(&queue_ptr, sizeof(queue_ptr), "queue_ptr", true);
    VOID (*queue_send_notify)(TX_QUEUE *notify_queue_ptr);
    klee_make_symbolic_controllable(&queue_send_notify, sizeof(queue_send_notify), "queue_send_notify", true);
    mqueue_send_notify(queue_ptr, queue_send_notify);
}
