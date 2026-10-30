// FLAGS: -O2 -g0 -mips2
#include "ultra64.h"

OSId osGetThreadId(OSThread *t) {
    if (t == NULL) {
        t = D_80098010;
    }
    return t->id;
}
