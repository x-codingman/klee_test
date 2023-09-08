#include "klee_help.h"
#include <stdlib.h>
#include <klee/klee.h>
int main()
{
size_t * arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
get_environ_ptr(arg0);

return 0;
}