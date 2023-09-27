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
    CHAR * name_ptr;
    klee_make_symbolic_controllable(&name_ptr, sizeof(name_ptr), "name_ptr", true);
    UINT message_size;
    klee_make_symbolic_controllable(&message_size, sizeof(message_size), "message_size", true);
    VOID * queue_start;
    klee_make_symbolic_controllable(&queue_start, sizeof(queue_start), "queue_start", true);
    ULONG queue_size;
    klee_make_symbolic_controllable(&queue_size, sizeof(queue_size), "queue_size", true);
    UINT queue_control_block_size;
    klee_make_symbolic_controllable(&queue_control_block_size, sizeof(queue_control_block_size), "queue_control_block_size", true);
    m_txe_queue_create(queue_ptr, name_ptr, message_size, queue_start, queue_size, queue_control_block_size);
}
