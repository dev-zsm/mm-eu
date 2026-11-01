// FLAGS: -O2 -g0 -mips2
#include "sdk/ultra64.h"

OSThread *__osGetActiveQueue(void) {
    return D_8009800C;
}
