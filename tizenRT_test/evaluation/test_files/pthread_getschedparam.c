#include "klee_help.h"
#include <pthread.h>
#include <klee/klee.h>
int main()
{
pthread_t arg0;
FAR int* arg1;
FAR struct sched_param* arg2;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
pthread_getschedparam(arg0, arg1, arg2);

return 0;
}