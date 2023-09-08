#include "klee_help.h"
#include <stdlib.h>
#include <klee/klee.h>
int main()
{
CODE void (*arg0)(int, FAR void *);

FAR void * arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);

on_exit(arg0, arg1);

return 0;
}