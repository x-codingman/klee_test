#include "klee_help.h"
#include <pthread.h>
#include <klee/klee.h>
int main()
{
pthread_addr_t arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
pthread_exit(arg0);

return 0;
}