// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800AFE80(s32, u8 *, M2C_UNK, M2C_UNK, s32, M2C_UNK *); /* extern */
M2C_UNK func_800E201C(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_808F6F28;
extern M2C_UNK D_808F7FA0;
extern s16 D_808F7FC8;
extern M2C_UNK D_808F7FCC;
extern M2C_UNK D_808F7FD4;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_808F7FCC);
    func_800E201C(arg1, arg0 + 0x188, arg0, &D_808F7FA0);
    M2C_FIELD(arg0, s16 *, 0x1D6) = (s16) D_808F7FC8;
    func_800AFE80(arg1, arg0 + 0x180, 2, 0, 0, &D_808F7FD4);
    func_800AFE80(arg1, arg0 + 0x184, 2, 0, 0, &D_808F7FD4);
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x78;
    M2C_FIELD(arg0, s8 *, 3) = -1;
    M2C_FIELD(arg0, s8 *, 0x148) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808F6F28;
    M2C_FIELD(arg0, f32 *, 0x174) = 0.0f;
}
