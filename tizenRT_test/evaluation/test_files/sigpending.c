#include "klee_help.h"
#include <signal.h>
#include <klee/klee.h>
int main()
{
FAR sigset_t* arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
sigpending(arg0);

return 0;
}