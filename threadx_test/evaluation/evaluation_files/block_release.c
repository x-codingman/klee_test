#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    VOID * block_ptr;
    klee_make_symbolic_controllable(&block_ptr, sizeof(block_ptr), "block_ptr", true);
    mblock_release(block_ptr);
}
