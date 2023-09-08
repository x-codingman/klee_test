#include "klee_help.h"
#include <assert.h>
#include <klee/klee.h>
int main()
{
FAR const uint8_t* arg0;
int arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
up_assert(arg0, arg1);

return 0;
}