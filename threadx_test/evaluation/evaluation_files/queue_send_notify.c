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
    VOID (*queue_send_notify)(TX_QUEUE *notify_queue_ptr);
    klee_make_symbolic_controllable(&queue_send_notify, sizeof(queue_send_notify), "queue_send_notify", true);
    m_txe_queue_send_notify(queue_ptr, queue_send_notify);
}
