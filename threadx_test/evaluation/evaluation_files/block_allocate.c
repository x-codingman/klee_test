#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_BLOCK_POOL * pool_ptr;
    klee_make_symbolic_controllable(&pool_ptr, sizeof(pool_ptr), "pool_ptr", true);
    VOID ** block_ptr;
    klee_make_symbolic_controllable(&block_ptr, sizeof(block_ptr), "block_ptr", true);
    ULONG wait_option;
    klee_make_symbolic_controllable(&wait_option, sizeof(wait_option), "wait_option", true);
    m_txe_block_allocate(pool_ptr, block_ptr, wait_option);
}
