#include "klee_help.h"
#include <sys/ioctl.h>
#include <klee/klee.h>
int main()
{
int arg0;
int arg1;
unsigned long arg2;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
ioctl(arg0, arg1, arg2);

return 0;
}