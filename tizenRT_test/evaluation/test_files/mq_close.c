#include "klee_help.h"
#include <mqueue.h>
#include <klee/klee.h>
int main()
{
mqd_t arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
mq_close(arg0);

return 0;
}