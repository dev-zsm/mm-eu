// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_8008942C(void **a0) {
    void *v = *a0;
    *a0 = *(void **)v;
}
