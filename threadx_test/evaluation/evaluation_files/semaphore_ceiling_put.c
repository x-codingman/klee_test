#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    TX_SEMAPHORE * semaphore_ptr;
    klee_make_symbolic_controllable(&semaphore_ptr, sizeof(semaphore_ptr), "semaphore_ptr", true);
    ULONG ceiling;
    klee_make_symbolic_controllable(&ceiling, sizeof(ceiling), "ceiling", true);
    msemaphore_ceiling_put(semaphore_ptr, ceiling);
}
