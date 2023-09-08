#include "klee_help.h"
#include <sys/stat.h>
#include <klee/klee.h>
int main()
{
FAR const char* arg0;
mode_t arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
mkdir(arg0, arg1);

return 0;
}