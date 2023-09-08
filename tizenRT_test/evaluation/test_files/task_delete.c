#include "klee_help.h"
#include <sched.h>
#include <klee/klee.h>
int main()
{
pid_t arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
task_delete(arg0);

return 0;
}