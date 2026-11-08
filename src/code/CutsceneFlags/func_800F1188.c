// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s32 CutsceneFlags_Get(struct PlayState *play, s16 flag) {
    return *(u16 *)((u8 *)play + 0x18B20 + (s16) (flag / 16) * 2) & (s16) (1 << (s16) (flag % 16));
}
