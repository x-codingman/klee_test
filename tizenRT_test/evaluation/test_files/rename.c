#include "klee_help.h"
#include <stdio.h>
#include <klee/klee.h>
int main()
{
FAR const char* arg0;
FAR const char* arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
rename(arg0, arg1);

return 0;
}