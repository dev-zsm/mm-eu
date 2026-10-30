// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B02EC(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E1C28(s32, u8 *, u8 *);         /* extern */
M2C_UNK func_80115F80(s32);                         /* extern */

void func_80000224(Actor *thisx, PlayState *play) {
    s16 temp_v0_2;
    u8 *temp_v0;

    if (M2C_FIELD(thisx, s16 *, 0x1C) < 6) {
        func_800B02EC(play, M2C_FIELD(thisx, s32 *, 0x240), thisx);
    }
    func_800E1C28(play, (u8 *)thisx + 0x1A8, thisx);
    temp_v0 = M2C_FIELD(thisx, u8 **, 0x264);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x138) != 0)) {
        M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(temp_v0, s32 *, 4) & 0xFFFF7FFF);
    }
    temp_v0_2 = M2C_FIELD(thisx, s16 *, 0x1C);
    if ((temp_v0_2 >= 3) && (temp_v0_2 < 6) && (M2C_FIELD(thisx, s32 *, 0x124) == 0)) {
        func_80115F80(play);
    }
}
