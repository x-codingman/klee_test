#include "klee_help.h"
#include <sys/socket.h>
#include <klee/klee.h>
int main()
{
int arg0;
int arg1;
int arg2;
FAR void* arg3;
FAR socklen_t* arg4;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
klee_make_symbolic_controllable(&arg3, sizeof(arg3), "arg3", true);
klee_make_symbolic_controllable(&arg4, sizeof(arg4), "arg4", true);
getsockopt(arg0, arg1, arg2, arg3, arg4);

return 0;
}