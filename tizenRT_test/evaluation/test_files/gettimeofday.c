#include "klee_help.h"
#include <sys/time.h>
#include <klee/klee.h>
int main()
{
struct timeval* arg0;
FAR struct timezone* arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
gettimeofday(arg0, arg1);

return 0;
}