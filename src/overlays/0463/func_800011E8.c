// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(u8 *, M2C_UNK *, u8 *);   /* extern */
extern M2C_UNK D_6004F14;
extern M2C_UNK D_600544C;
extern M2C_UNK D_80AFCAA8;

void func_800011E8(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
        func_801377D0(arg0 + 0x144, &D_6004F14, arg0);
        M2C_FIELD(arg0, f32 *, 0x298) = 17.0f;
    } else {
        func_801377D0(arg0 + 0x144, &D_600544C, arg0);
        M2C_FIELD(arg0, f32 *, 0x298) = 15.0f;
    }
    M2C_FIELD(arg0, s16 *, 0x28C) = (s16) (M2C_FIELD(arg0, s16 *, 0x28C) - 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_80AFCAA8;
}
