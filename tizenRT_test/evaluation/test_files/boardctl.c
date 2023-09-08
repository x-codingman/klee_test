#include "klee_help.h"
#include <sys/boardctl.h>
#include <klee/klee.h>
int main()
{
unsigned int arg0;
uintptr_t arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
boardctl(arg0, arg1);

return 0;
}