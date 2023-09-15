#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    TX_BLOCK_POOL * pool_ptr;
    klee_make_symbolic_controllable(&pool_ptr, sizeof(pool_ptr), "pool_ptr", true);
    VOID ** block_ptr;
    klee_make_symbolic_controllable(&block_ptr, sizeof(block_ptr), "block_ptr", true);
    ULONG wait_option;
    klee_make_symbolic_controllable(&wait_option, sizeof(wait_option), "wait_option", true);
    mblock_allocate(pool_ptr, block_ptr, wait_option);
}
