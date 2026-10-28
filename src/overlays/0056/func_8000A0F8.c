// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80151DF4(s32, u16, s32);               /* extern */
M2C_UNK func_80830DDC(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_8084E074;

void func_8000A0F8(s32 arg0, u8 *arg1) {
    u16 temp_a1;

    func_80830DDC(arg0, arg1, &D_8084E074, 0);
    temp_a1 = M2C_FIELD(arg1, u16 *, 0x116);
    M2C_FIELD(arg1, s8 *, 0xA87) = 0;
    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) | 0x20000040);
    if (temp_a1 != 0) {
        func_80151DF4(arg0, temp_a1, M2C_FIELD(arg1, s32 *, 0xA88));
    }
    M2C_FIELD(arg1, s32 *, 0x730) = (s32) M2C_FIELD(arg1, s32 *, 0xA88);
}
