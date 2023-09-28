#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_QUEUE * queue_ptr;
    klee_make_symbolic_controllable(&queue_ptr, sizeof(queue_ptr), "queue_ptr", true);
    VOID * destination_ptr;
    klee_make_symbolic_controllable(&destination_ptr, sizeof(destination_ptr), "destination_ptr", true);
    ULONG wait_option;
    klee_make_symbolic_controllable(&wait_option, sizeof(wait_option), "wait_option", true);
    m_txe_queue_receive(queue_ptr, destination_ptr, wait_option);
}
