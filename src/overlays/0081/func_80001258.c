// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BBB30(s32, u8 *, u8 *, M2C_UNK, s32, f32, s32, s32, s32); /* extern */
M2C_UNK func_8012AD58(s16, M2C_UNK);                /* extern */
M2C_UNK func_8012ADA0(s16, M2C_UNK);                /* extern */
M2C_UNK func_8012AE28(s16, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s16 func_8012AF4C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_8013F090(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_8016A844(s32, M2C_UNK);                    /* extern */
M2C_UNK func_808A0FA4(u8 *, s32);                 /* extern */
s32 func_808A1190(u8 *);                          /* extern */

void func_80001258(u8 *arg0, s32 arg1) {
    s16 sp3E;
    s16 temp_v0;

    if (func_808A1190(arg0) != 0) {
        if (M2C_FIELD(arg0, f32 *, 0x68) > 20.0f) {
            M2C_FIELD(arg0, f32 *, 0x88) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
            func_800BBB30(arg1, arg0, arg0 + 0x24, 0x42340000, 0xA, 8.0f, 0x1F4, 0xA, 0);
        }
        func_800B8C4C(arg0, 0x281D);
        temp_v0 = func_8012AF4C(func_8016A844(arg1, 0), 3);
        sp3E = temp_v0;
        func_8012AD58(temp_v0, -0x7F18);
        func_8012AE28(sp3E, 2, 0, 0, 0);
        func_8012ADA0(sp3E, 0xA);
        func_8013F090(M2C_FIELD(arg0, f32 *, 0x94), 0xB4, 0x14, 0x64);
        func_808A0FA4(arg0, arg1);
    }
}
