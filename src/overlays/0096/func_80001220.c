// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFAD8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_808B7B70(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_808B8E5C;
extern f32 D_808BB2BC;
extern f32 D_808BB2C0;

void func_80001220(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;

    func_800B8C4C(arg0, 0x2025);
    func_800FFAD8(arg0 + 0x1B0, 0x437F0000, 0x3ECCCCCD, 0x41200000, D_808BB2BC);
    func_800FFAD8(arg0 + 0x1B4, 0x437F0000, 0x3ECCCCCD, 0x41200000, D_808BB2C0);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C4);
    if (temp_v0 < 0x64) {
        M2C_FIELD(arg0, s16 *, 0x1C4) = (s16) (temp_v0 + 2);
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x1C6);
    if (temp_v0_2 < 0x78) {
        M2C_FIELD(arg0, s16 *, 0x1C6) = (s16) (temp_v0_2 + 4);
    }
    temp_v0_3 = M2C_FIELD(arg0, s16 *, 0x1C8);
    if (temp_v0_3 < 0xE6) {
        M2C_FIELD(arg0, s16 *, 0x1C8) = (s16) (temp_v0_3 + 4);
        return;
    }
    func_808B7B70(arg0, &D_808B8E5C);
}
