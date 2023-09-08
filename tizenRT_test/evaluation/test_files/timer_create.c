#include "klee_help.h"
#include <time.h>
#include <klee/klee.h>
int main()
{
clockid_t arg0;
FAR struct sigevent* arg1;
FAR timer_t* arg2;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
timer_create(arg0, arg1, arg2);

return 0;
}