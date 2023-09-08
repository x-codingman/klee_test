#include "klee_help.h"
#include <semaphore.h>
#include <klee/klee.h>
int main()
{
FAR const char* arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
sem_unlink(arg0);

return 0;
}