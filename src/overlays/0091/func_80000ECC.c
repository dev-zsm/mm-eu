// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_800BB80C(s32, u8 *);                 /* extern */
s32 func_800BDFB0(u8 *);                          /* extern */
M2C_UNK func_800BDFDC(u8 *, u8 *);              /* extern */
M2C_UNK func_808AFDB0(u8 *, s32);                 /* extern */
extern f32 D_808B0890;

s32 func_80000ECC(u8 *arg0, s32 arg1) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x2F9);
    if (temp_v0 & 2) {
        M2C_FIELD(arg0, u8 *, 0x2F9) = (u8) (temp_v0 & 0xFFFD);
        func_800BDFDC(arg0, arg0 + 0x300);
        if (func_800BDFB0(arg0) == 0) {
            func_800BB80C(arg1, arg0);
        }
        if (M2C_FIELD(arg0, u8 *, 0xB9) == 0xD) {
            return 1;
        }
        if (M2C_FIELD(arg0, u8 *, 0xB7) != 0) {
            M2C_FIELD(arg0, u8 *, 0x2F8) = (u8) (M2C_FIELD(arg0, u8 *, 0x2F8) & 0xFFFE);
        }
        M2C_FIELD(arg0, u8 *, 0x2F8) = (u8) (M2C_FIELD(arg0, u8 *, 0x2F8) & 0xFFFD);
        if (M2C_FIELD(arg0, u8 *, 0xB9) == 4) {
            M2C_FIELD(arg0, f32 *, 0x248) = (f32) D_808B0890;
            M2C_FIELD(arg0, f32 *, 0x244) = 4.0f;
            func_800BA9E4(arg1 + 0x1CA0, arg1, 0xA2, (f32) M2C_FIELD(arg0, s16 *, 0x30E), (f32) M2C_FIELD(arg0, s16 *, 0x310), (f32) M2C_FIELD(arg0, s16 *, 0x312), 0, 0, 0, 4);
        }
        func_808AFDB0(arg0, arg1);
        return 1;
    }
    return 0;
}
