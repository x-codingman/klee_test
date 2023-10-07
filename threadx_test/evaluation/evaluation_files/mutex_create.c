#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

UCHAR                   pool_start[9120];

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_MUTEX * mutex_ptr;
    klee_make_symbolic_controllable(&mutex_ptr, sizeof(mutex_ptr), "mutex_ptr", true);
    CHAR * name_ptr;
    klee_make_symbolic_controllable(&name_ptr, sizeof(name_ptr), "name_ptr", true);
    UINT inherit;
    klee_make_symbolic_controllable(&inherit, sizeof(inherit), "inherit", true);
    UINT mutex_control_block_size;
    klee_make_symbolic_controllable(&mutex_control_block_size, sizeof(mutex_control_block_size), "mutex_control_block_size", true);
    m_txe_mutex_create(mutex_ptr, name_ptr, inherit, mutex_control_block_size);
}
