#include "klee_help.h"
#include <time.h>
#include <klee/klee.h>
int main()
{
timer_t arg0;
int arg1;
FAR const struct itimerspec* arg2;
FAR struct itimerspec* arg3;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
klee_make_symbolic_controllable(&arg3, sizeof(arg3), "arg3", true);
timer_settime(arg0, arg1, arg2, arg3);

return 0;
}