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
    TX_SEMAPHORE * semaphore_ptr;
    klee_make_symbolic_controllable(&semaphore_ptr, sizeof(semaphore_ptr), "semaphore_ptr", true);
    CHAR * name_ptr;
    klee_make_symbolic_controllable(&name_ptr, sizeof(name_ptr), "name_ptr", true);
    ULONG initial_count;
    klee_make_symbolic_controllable(&initial_count, sizeof(initial_count), "initial_count", true);
    UINT semaphore_control_block_size;
    klee_make_symbolic_controllable(&semaphore_control_block_size, sizeof(semaphore_control_block_size), "semaphore_control_block_size", true);
    m_txe_semaphore_create(semaphore_ptr, name_ptr, initial_count, semaphore_control_block_size);
}
