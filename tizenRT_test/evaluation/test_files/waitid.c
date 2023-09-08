#include "klee_help.h"
#include <sys/wait.h>
#include <klee/klee.h>
int main()
{
idtype_t arg0;
id_t arg1;
FAR siginfo_t * arg2;
int arg3;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
klee_make_symbolic_controllable(&arg3, sizeof(arg3), "arg3", true);
waitid(arg0, arg1, arg2, arg3);

return 0;
}