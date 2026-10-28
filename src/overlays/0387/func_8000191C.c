// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80137C58(u8 *, M2C_UNK);                 /* extern */
extern s32 D_801EAB9C;

void func_8000191C(u8 *arg0, u8 *arg1) {
    u16 temp_v0;

    if ((M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) && (M2C_FIELD(arg1, s16 *, 0xA4) == 0x38) && (D_801EAB9C == 0) && (M2C_FIELD(arg1, u16 *, 0x1F36) == 0)) {
        temp_v0 = M2C_FIELD(arg1, u16 *, 0x1F34);
        if (((s32) temp_v0 >= 0x37A) && ((s32) temp_v0 < 0x39A)) {
            func_800B8C4C(arg0, 0x2159);
        }
    }
    if ((M2C_FIELD(arg0, u8 *, 0x202) == 1) && (func_80137C58(arg0 + 0x15C, 0x41800000) != 0)) {
        func_800B8C4C(arg0, 0x28D6);
    }
}
