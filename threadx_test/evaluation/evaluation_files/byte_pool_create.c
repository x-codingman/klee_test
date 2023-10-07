#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

UCHAR                   pool_start[9120];

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_BYTE_POOL * pool_ptr;
    klee_make_symbolic_controllable(&pool_ptr, sizeof(pool_ptr), "pool_ptr", true);
    CHAR * name_ptr;
    klee_make_symbolic_controllable(&name_ptr, sizeof(name_ptr), "name_ptr", true);
    ULONG pool_size;
    klee_make_symbolic_controllable(&pool_size, sizeof(pool_size), "pool_size", true);
    UINT pool_control_block_size;
    klee_make_symbolic_controllable(&pool_control_block_size, sizeof(pool_control_block_size), "pool_control_block_size", true);
    m_txe_byte_pool_create(pool_ptr, name_ptr, pool_start, pool_size, pool_control_block_size);
}
