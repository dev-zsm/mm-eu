// FLAGS: -O2 -g0 -mips2
#include "types.h"

void __osContGetInitData(u8 *dst, s32 src);

void osContGetQuery(s32 a0) {
    u8 buf;

    __osContGetInitData(&buf, a0);
}
