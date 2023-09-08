#include "klee_help.h"
#include <signal.h>
#include <klee/klee.h>
int main()
{
FAR const sigset_t* arg0;
FAR struct siginfo* arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
sigwaitinfo(arg0, arg1);

return 0;
}