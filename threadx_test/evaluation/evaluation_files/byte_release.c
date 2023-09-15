#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    VOID * memory_ptr;
    klee_make_symbolic_controllable(&memory_ptr, sizeof(memory_ptr), "memory_ptr", true);
    mbyte_release(memory_ptr);
}
