#include "klee_help.h"
#include <semaphore.h>
#include <klee/klee.h>
int main()
{
FAR sem_t* arg0;
FAR const struct timespec * arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
sem_timedwait(arg0, arg1);

return 0;
}