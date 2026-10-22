// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 memcpy(void);

s32 func_800879D0(s32 a0, s32 a1, s32 a2) {
    return memcpy() + a2;
}
