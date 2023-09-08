#include "klee_help.h"
#include <pthread.h>
#include <klee/klee.h>
int main()
{
FAR pthread_cond_t* arg0;
FAR pthread_mutex_t* arg1;
FAR const struct timespec* arg2;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
pthread_cond_timedwait(arg0, arg1, arg2);

return 0;
}