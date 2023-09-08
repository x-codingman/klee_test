#include "klee_help.h"
#include <sys/shm.h>
#include <klee/klee.h>
int main()
{
FAR const void * arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
shmdt(arg0);

return 0;
}