// FLAGS: -O2 -g0 -mips2
#include "ultra64.h"

OSThread *__osGetCurrFaultedThread(void) {
    return D_80098014;
}
