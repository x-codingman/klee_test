#include "klee_help.h"
#include <stdlib.h>
#include <klee/klee.h>
int main()
{
FAR const char* arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
putenv(arg0);

return 0;
}