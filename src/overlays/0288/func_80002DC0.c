// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80182B28(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_809D3398(M2C_UNK, s32, M2C_UNK *);     /* extern */
extern M2C_UNK D_809D6A00;
extern M2C_UNK D_809D6A0C;
extern M2C_UNK D_809D6E40;

void func_80002DC0(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4) {
    if (arg1 == 1) {
        func_80182B28(&D_809D6A00, &D_809D6E40);
        func_809D3398(0, arg4 + 0x368, &D_809D6E40);
        if (M2C_FIELD(arg4, s16 *, 0x1C) == 4) {
            func_80182B28(&D_809D6A0C, arg4 + 0x3C);
        }
        if (M2C_FIELD(arg4, u8 *, 0x188) != 0) {
            func_80182B28(&D_809D6A0C, arg4 + 0x18C);
            if (M2C_FIELD(arg4, u8 *, 0x189) == 0) {
                M2C_FIELD(arg4, f32 *, 0x190) = (f32) (M2C_FIELD(arg4, f32 *, 0x190) - 15.0f);
            }
        }
    }
}
