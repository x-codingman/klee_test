#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

UCHAR                   pool_start[9120];

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_SEMAPHORE * semaphore_ptr;
    klee_make_symbolic_controllable(&semaphore_ptr, sizeof(semaphore_ptr), "semaphore_ptr", true);
    m_txe_semaphore_put(semaphore_ptr);
}
