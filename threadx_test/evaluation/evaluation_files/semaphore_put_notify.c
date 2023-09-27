#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    TX_SEMAPHORE * semaphore_ptr;
    klee_make_symbolic_controllable(&semaphore_ptr, sizeof(semaphore_ptr), "semaphore_ptr", true);
    VOID (*semaphore_put_notify)(TX_SEMAPHORE *notify_semaphore_ptr);
    klee_make_symbolic_controllable(&semaphore_put_notify, sizeof(semaphore_put_notify), "semaphore_put_notify", true);
    m_txe_semaphore_put_notify(semaphore_ptr, semaphore_put_notify);
}
