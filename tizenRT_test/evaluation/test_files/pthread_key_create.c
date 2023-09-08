#include "klee_help.h"
#include <pthread.h>
#include <klee/klee.h>
int main()
{
FAR pthread_key_t* arg0;
CODE void (*arg1)(FAR void*) ;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
pthread_key_create(arg0, arg1);

return 0;
}