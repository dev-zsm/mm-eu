// FLAGS: -O2 -g0 -mips2
#include "sdk/ultra64.h"

OSPri osGetThreadPri(OSThread *t) {
    if (t == NULL) {
        t = D_80098010;
    }
    return t->priority;
}
