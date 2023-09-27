#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    TX_BLOCK_POOL * pool_ptr;
    klee_make_symbolic_controllable(&pool_ptr, sizeof(pool_ptr), "pool_ptr", true);
    m_txe_block_pool_delete(pool_ptr);
}
