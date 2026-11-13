// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_801A0070(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808C5E98(u8 *);                      /* extern */
extern f32 D_808C927C;

void func_80001728(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 temp_v1;

    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 4, 0x1000, 0x200);
    func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0xC), 0x40400000);
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (s32) ((100.0f - M2C_FIELD(arg0, f32 *, 0x98)) * D_808C927C * 1024.0f);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0xBC);
    if (temp_v1 < 0) {
        M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0xBC) = temp_v1;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2EE);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2EE) = (s16) (temp_v0 + 1);
        if (M2C_FIELD(arg0, s16 *, 0x2EE) == 3) {
            func_808C5E98(arg0);
        }
    } else if ((func_80137070(arg0 + 0x144) != 0) && (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f)) {
        func_801A0070(arg0 + 0x338, 0x3AAC);
        M2C_FIELD(arg0, s16 *, 0x2EE) = (s16) (M2C_FIELD(arg0, s16 *, 0x2EE) + 1);
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
}
