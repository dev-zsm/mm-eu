// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800AFE80(s32, u8 *, M2C_UNK, M2C_UNK, s32, M2C_UNK *); /* extern */
M2C_UNK func_800E201C(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_808F6F28;
extern M2C_UNK D_808F7FA0;
extern s16 D_808F7FC8;
extern M2C_UNK D_808F7FCC;
extern M2C_UNK D_808F7FD4;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800FF8DC(thisx, &D_808F7FCC);
    func_800E201C(play, (u8 *)thisx + 0x188, thisx, &D_808F7FA0);
    M2C_FIELD(thisx, s16 *, 0x1D6) = (s16) D_808F7FC8;
    func_800AFE80(play, (u8 *)thisx + 0x180, 2, 0, 0, &D_808F7FD4);
    func_800AFE80(play, (u8 *)thisx + 0x184, 2, 0, 0, &D_808F7FD4);
    M2C_FIELD(thisx, s16 *, 0x14A) = 0x78;
    M2C_FIELD(thisx, s8 *, 3) = -1;
    M2C_FIELD(thisx, s8 *, 0x148) = 1;
    M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_808F6F28;
    M2C_FIELD(thisx, f32 *, 0x174) = 0.0f;
}
