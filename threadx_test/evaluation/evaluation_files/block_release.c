#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    VOID * block_ptr;
    klee_make_symbolic_controllable(&block_ptr, sizeof(block_ptr), "block_ptr", true);
    mblock_release(block_ptr);
}
