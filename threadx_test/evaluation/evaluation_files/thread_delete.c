#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
<<<<<<< HEAD
=======
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
>>>>>>> f76cfda5d8408d39259c89e8e971e97c6ee9f1ea
    TX_THREAD * thread_ptr;
    klee_make_symbolic_controllable(&thread_ptr, sizeof(thread_ptr), "thread_ptr", true);
    m_txe_thread_delete(thread_ptr);
}
