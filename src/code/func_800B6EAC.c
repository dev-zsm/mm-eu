// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern s32 func_800B6E9C();
s32 func_800B6EAC(s32 a0) {
    return func_800B6E9C(a0) != 0 && *(s16 *)(a0 + 0xACC) != 0;
}
