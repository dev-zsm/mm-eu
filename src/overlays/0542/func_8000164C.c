// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E0F5C(s32, s32);                    /* extern */
M2C_UNK func_800E10CC(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
s32 func_8013D9F8(s32, s16, M2C_UNK);               /* extern */
extern M2C_UNK D_80B8E220;
extern M2C_UNK D_80B8F1D0;
extern M2C_UNK D_80B8F1FC;
extern M2C_UNK D_80B8F208;

void func_8000164C(Actor *thisx, PlayState *play) {
    s32 sp24;
    s32 temp_a1;

    temp_a1 = (u8 *)thisx + 0x194;
    sp24 = temp_a1;
    func_800E0F5C(play, temp_a1);
    func_800E10CC(play, temp_a1, thisx, &D_80B8F1D0);
    func_800E731C((u8 *)thisx + 0xA0, &D_80B8F208, &D_80B8F1FC);
    M2C_FIELD(thisx, s32 *, 0x1E4) = func_8013D9F8(play, (s16) ((s32) (M2C_FIELD(thisx, s16 *, 0x1C) & 0x3F00) >> 8), 0x3F);
    func_800B6564(thisx, 0x3C23D70A);
    M2C_FIELD(thisx, s8 *, 0x1F) = 0;
    M2C_FIELD(thisx, M2C_UNK **, 0x148) = &D_80B8E220;
    M2C_FIELD(thisx, f32 *, 0x74) = -4.0f;
}
