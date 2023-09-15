#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    TX_QUEUE * queue_ptr;
    klee_make_symbolic_controllable(&queue_ptr, sizeof(queue_ptr), "queue_ptr", true);
    VOID * destination_ptr;
    klee_make_symbolic_controllable(&destination_ptr, sizeof(destination_ptr), "destination_ptr", true);
    ULONG wait_option;
    klee_make_symbolic_controllable(&wait_option, sizeof(wait_option), "wait_option", true);
    mqueue_receive(queue_ptr, destination_ptr, wait_option);
}
