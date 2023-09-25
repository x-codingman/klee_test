#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    TX_MUTEX * mutex_ptr;
    klee_make_symbolic_controllable(&mutex_ptr, sizeof(mutex_ptr), "mutex_ptr", true);
    mmutex_prioritize(mutex_ptr);
}
