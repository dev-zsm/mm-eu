#include "types.h"
#include "m2c_compat.h"

s16 func_800B6AB0(u8 *, u8 *);                  /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_800DFA9C(s32);                             /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
s32 func_8016A844(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_8016A87C(u8 *, s16, s32, s32);       /* extern */
extern M2C_UNK D_600F990;
extern M2C_UNK D_808E809C;

void func_800038F8(u8 *arg0, u8 *arg1) {
    s16 temp_v1;
    s32 temp_v0;

    temp_v0 = func_8016A844(arg1, 0);
    func_8016A87C(arg1, M2C_FIELD(arg0, s16 *, 0x2C6), temp_v0 + 0x50, temp_v0 + 0x5C);
    M2C_FIELD(arg0, s16 *, 0x2BA) = 0xF;
    M2C_FIELD(arg0, s16 *, 0x2BC) = 0;
    M2C_FIELD(arg0, u8 *, 0x688) = (u8) (M2C_FIELD(arg0, u8 *, 0x688) & 0xFFFE);
    M2C_FIELD(arg0, s16 *, 0x32) = func_800B6AB0(arg0, arg0 + 8);
    temp_v1 = func_800DFA9C(((s32 *)(arg1 + 0x800))[M2C_FIELD(arg1, s16 *, 0x810)]) - M2C_FIELD(arg0, s16 *, 0x32);
    if (temp_v1 >= 0x4001) {
        M2C_FIELD(arg0, s16 *, 0x2C8) = -0x2000;
    } else if (temp_v1 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2C8) = -0x6000;
    } else if (temp_v1 < -0x4000) {
        M2C_FIELD(arg0, s16 *, 0x2C8) = 0x2000;
    } else {
        M2C_FIELD(arg0, s16 *, 0x2C8) = 0x6000;
    }
    M2C_FIELD(arg0, s16 *, 0x2C8) = (s16) (M2C_FIELD(arg0, s16 *, 0x32) + M2C_FIELD(arg0, s16 *, 0x2C8));
    func_801378E0(arg0 + 0x144, &D_600F990);
    func_800B8C4C(arg0, 0x38D4);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E809C;
}
