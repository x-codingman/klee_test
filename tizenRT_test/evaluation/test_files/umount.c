#include "klee_help.h"
#include <sys/mount.h>
#include <klee/klee.h>
int main()
{
const char* arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
umount(arg0);

return 0;
}