#include "klee_help.h"
#include <time.h>
#include <klee/klee.h>
int main()
{
timer_t arg0;
FAR struct itimerspec* arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
timer_gettime(arg0, arg1);

return 0;
}