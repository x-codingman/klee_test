#include "klee_help.h"
#include <mqueue.h>
#include <klee/klee.h>
int main()
{
mqd_t arg0;
const struct mq_attr * arg1;
struct mq_attr * arg2;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
klee_make_symbolic_controllable(&arg1, sizeof(arg1), "arg1", true);
klee_make_symbolic_controllable(&arg2, sizeof(arg2), "arg2", true);
mq_setattr(arg0, arg1, arg2);

return 0;
}