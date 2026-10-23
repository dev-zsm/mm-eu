// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 memcpy(s32 a0, s32 a1, s32 a2);

s32 func_800879D0(s32 a0, s32 a1, s32 a2) {
    return memcpy(a0, a1, a2) + a2;
}
