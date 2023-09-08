#include "klee_help.h"
#include <unistd.h>
#include <klee/klee.h>
int main()
{
int arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
fsync(arg0);

return 0;
}