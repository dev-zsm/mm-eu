// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800DFFF8(s32);                         /* extern */
s32 func_8016A844(s32, M2C_UNK);                    /* extern */
M2C_UNK func_8082D2E8(u8 *);                      /* extern */
M2C_UNK func_8082D314(s32, u8 *);                 /* extern */

void func_8000029C(s32 arg0, u8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0xA6C);
    if ((temp_v0 & 0x800) && (M2C_FIELD(arg1, s32 *, 0x34C) == 0)) {
        if (M2C_FIELD(arg1, s32 *, 0x388) != 0) {
            if (M2C_FIELD(arg1, s16 *, 0x384) == 0) {
                M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (temp_v0 & ~0x800);
                M2C_FIELD(arg1, s32 *, 0x388) = 0;
            }
        } else {
            M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (temp_v0 & ~0x800);
        }
    }
    func_8082D2E8(arg1);
    M2C_FIELD(arg1, s8 *, 0xAA5) = 0;
    func_8082D314(arg0, arg1);
    func_800DFFF8(func_8016A844(arg0, 0));
    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) & 0xFFCF9FFB);
    M2C_FIELD(arg1, s32 *, 0xA70) = (s32) (M2C_FIELD(arg1, s32 *, 0xA70) & ~0x90);
    M2C_FIELD(arg1, s8 *, 0xADD) = 0;
    M2C_FIELD(arg1, s8 *, 0xADC) = 0;
    M2C_FIELD(arg1, s16 *, 0xBC) = 0;
    M2C_FIELD(arg1, s16 *, 0xC0) = 0;
    M2C_FIELD(arg1, f32 *, 0xABC) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0xAC0) = 0.0f;
}
