// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 func_8008F3A8(void);

s32 func_800879D0(s32 a0, s32 a1, s32 a2) {
    return func_8008F3A8() + a2;
}
