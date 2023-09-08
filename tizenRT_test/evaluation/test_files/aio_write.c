#include "klee_help.h"
#include <aio.h>
#include <klee/klee.h>
int main()
{
FAR struct aiocb * arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
aio_write(arg0);

return 0;
}