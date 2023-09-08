#include "klee_help.h"
#include <unistd.h>
#include <klee/klee.h>
int main()
{

vfork();

return 0;
}