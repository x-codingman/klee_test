#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    TX_QUEUE * queue_ptr;
    klee_make_symbolic_controllable(&queue_ptr, sizeof(queue_ptr), "queue_ptr", true);
    mqueue_prioritize(queue_ptr);
}
