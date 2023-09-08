#include "klee_help.h"
#include <stdlib.h>
#include <klee/klee.h>
int main()
{
void (*arg0)(void);
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
atexit(arg0);

return 0;
}