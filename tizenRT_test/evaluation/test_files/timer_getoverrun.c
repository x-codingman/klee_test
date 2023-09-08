#include "klee_help.h"
#include <time.h>
#include <klee/klee.h>
int main()
{
timer_t arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
timer_getoverrun(arg0);

return 0;
}