// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */
extern s16 D_801EAE48;
extern u8 *D_801EB7E0;
extern f32 D_809581C4;

void func_800001C4(u8 *arg0, u8 *arg1) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x16C);
    if (temp_f0 > 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x16C) = (f32) (temp_f0 - D_809581C4);
        return;
    }
    func_800B6490();
    if ((M2C_FIELD(D_801EB7E0, s16 *, 0x32) != 0x190) && (M2C_FIELD(arg1, s16 *, 0x16952) == 0)) {
        if ((M2C_FIELD(arg1, u16 *, 0x16938) != 0x39) || (M2C_FIELD(arg1, u16 *, 0x16936) != 0xA)) {
            D_801EAE48 = 1;
        }
    } else {
        M2C_FIELD(arg1, u16 *, 0x16936) = 4U;
    }
}
