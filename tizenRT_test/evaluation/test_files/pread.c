#include "klee_help.h"
#include <unistd.h>
#include <klee/klee.h>
int main()
{
int arg0;
FAR void* arg1;
size_t arg2;
off_t arg3;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
klee_make_symbolic_controllable(&arg3, sizeof(arg3), "arg3", true);
pread(arg0, arg1, arg2, arg3);

return 0;
}