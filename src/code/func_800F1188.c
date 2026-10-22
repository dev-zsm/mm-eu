// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 CutsceneFlags_Get(u8 *arg0, s16 arg1) {
    return *(u16 *)(arg0 + 0x18B20 + (s16) (arg1 / 16) * 2) & (s16) (1 << (s16) (arg1 % 16));
}
