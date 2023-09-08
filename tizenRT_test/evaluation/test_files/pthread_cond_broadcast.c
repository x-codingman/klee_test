#include "klee_help.h"
#include <pthread.h>
#include <klee/klee.h>
int main()
{
FAR pthread_cond_t* arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
pthread_cond_broadcast(arg0);

return 0;
}