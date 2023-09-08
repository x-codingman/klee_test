#include "klee_help.h"
#include <mqueue.h>
#include <klee/klee.h>
int main()
{
mqd_t arg0;
const struct sigevent* arg1;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
mq_notify(arg0, arg1);

return 0;
}