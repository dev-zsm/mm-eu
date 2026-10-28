// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(u8 *, M2C_UNK *, u8 *);   /* extern */
extern M2C_UNK D_6000404;
extern M2C_UNK D_60007B4;
extern M2C_UNK D_80AFC788;

void func_80000ED0(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(arg0, f32 *, 0x58);
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
        M2C_FIELD(arg0, f32 *, 0x298) = 15.0f;
        func_801377D0(arg0 + 0x144, &D_6000404, arg0);
    } else {
        M2C_FIELD(arg0, f32 *, 0x298) = 6.0f;
        func_801377D0(arg0 + 0x144, &D_60007B4, arg0);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_80AFC788;
}
