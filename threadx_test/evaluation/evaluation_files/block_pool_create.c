#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    TX_BLOCK_POOL * pool_ptr;
    klee_make_symbolic_controllable(&pool_ptr, sizeof(pool_ptr), "pool_ptr", true);
    CHAR * name_ptr;
    klee_make_symbolic_controllable(&name_ptr, sizeof(name_ptr), "name_ptr", true);
    ULONG block_size;
    klee_make_symbolic_controllable(&block_size, sizeof(block_size), "block_size", true);
    VOID * pool_start;
    klee_make_symbolic_controllable(&pool_start, sizeof(pool_start), "pool_start", true);
    ULONG pool_size;
    klee_make_symbolic_controllable(&pool_size, sizeof(pool_size), "pool_size", true);
    UINT pool_control_block_size;
    klee_make_symbolic_controllable(&pool_control_block_size, sizeof(pool_control_block_size), "pool_control_block_size", true);
    mblock_pool_create(pool_ptr, name_ptr, block_size, pool_start, pool_size, pool_control_block_size);
}
