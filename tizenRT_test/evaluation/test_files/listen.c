#include "klee_help.h"
#include <sys/socket.h>
#include <klee/klee.h>
int main()
{
int arg0;
int arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
listen(arg0, arg1);

return 0;
}