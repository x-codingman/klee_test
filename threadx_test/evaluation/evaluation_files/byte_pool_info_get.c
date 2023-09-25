#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    TX_BYTE_POOL * pool_ptr;
    klee_make_symbolic_controllable(&pool_ptr, sizeof(pool_ptr), "pool_ptr", true);
    CHAR ** name;
    klee_make_symbolic_controllable(&name, sizeof(name), "name", true);
    ULONG * available_bytes;
    klee_make_symbolic_controllable(&available_bytes, sizeof(available_bytes), "available_bytes", true);
    ULONG * fragments;
    klee_make_symbolic_controllable(&fragments, sizeof(fragments), "fragments", true);
    TX_THREAD ** first_suspended;
    klee_make_symbolic_controllable(&first_suspended, sizeof(first_suspended), "first_suspended", true);
    ULONG * suspended_count;
    klee_make_symbolic_controllable(&suspended_count, sizeof(suspended_count), "suspended_count", true);
    TX_BYTE_POOL ** next_pool;
    klee_make_symbolic_controllable(&next_pool, sizeof(next_pool), "next_pool", true);
    mbyte_pool_info_get(pool_ptr, name, available_bytes, fragments, first_suspended, suspended_count, next_pool);
}
