// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B02EC(s32, s32);                    /* extern */
M2C_UNK func_800E1F64(s32, u8 *);                 /* extern */

void func_80000220(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(thisx, s16 *, 0x1C) == 0) {
        func_800B02EC(play, M2C_FIELD(thisx, s32 *, 0x260));
        func_800B02EC(play, M2C_FIELD(thisx, s32 *, 0x264));
    }
    func_800E1F64(play, (u8 *)thisx + 0x268);
}
