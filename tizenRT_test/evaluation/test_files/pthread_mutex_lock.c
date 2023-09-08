#include "klee_help.h"
#include <pthread.h>
#include <klee/klee.h>
int main()
{
FAR pthread_mutex_t* arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
pthread_mutex_lock(arg0);

return 0;
}