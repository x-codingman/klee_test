#include "klee_help.h"
#include <dirent.h>
#include <klee/klee.h>
int main()
{
FAR DIR* arg0;
klee_make_symbolic_controllable(&arg0, sizeof(arg0), "arg0", true);
rewinddir(arg0);

return 0;
}