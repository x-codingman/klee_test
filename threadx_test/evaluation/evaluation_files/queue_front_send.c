#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
<<<<<<< HEAD
=======
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
>>>>>>> f76cfda5d8408d39259c89e8e971e97c6ee9f1ea
    TX_QUEUE * queue_ptr;
    klee_make_symbolic_controllable(&queue_ptr, sizeof(queue_ptr), "queue_ptr", true);
    VOID * source_ptr;
    klee_make_symbolic_controllable(&source_ptr, sizeof(source_ptr), "source_ptr", true);
    ULONG wait_option;
    klee_make_symbolic_controllable(&wait_option, sizeof(wait_option), "wait_option", true);
    m_txe_queue_front_send(queue_ptr, source_ptr, wait_option);
}
