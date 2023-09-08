#include "klee_help.h"
#include <sys/mman.h>
#include <klee/klee.h>
int main()
{
FAR void* arg0;
size_t arg1;
int arg2;
int arg3;
int arg4;
off_t arg5;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
klee_make_symbolic_controllable(&arg3, sizeof(arg3), "arg3", true);
klee_make_symbolic_controllable(&arg4, sizeof(arg4), "arg4", true);
klee_make_symbolic_controllable(&arg5, sizeof(arg5), "arg5", true);
mmap(arg0, arg1, arg2, arg3, arg4, arg5);

return 0;
}