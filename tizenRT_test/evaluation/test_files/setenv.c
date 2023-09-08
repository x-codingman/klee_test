#include "klee_help.h"
#include <stdlib.h>
#include <klee/klee.h>
int main()
{
const char* arg0;
const char* arg1;
int arg2;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
setenv(arg0, arg1, arg2);

return 0;
}