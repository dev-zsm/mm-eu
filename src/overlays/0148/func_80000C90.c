// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB44(s16, u8 *);                     /* extern */
f32 func_800FEB84(s16, u8 *);                     /* extern */
extern M2C_UNK D_80913CF8;

void func_80000C90(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x220) = 0x28;
    M2C_FIELD(arg0, f32 *, 0x68) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x64) = (f32) (2.0f * func_800FEB84(M2C_FIELD(arg0, s16 *, 0x32), arg0));
    M2C_FIELD(arg0, f32 *, 0x6C) = (f32) (2.0f * func_800FEB44(M2C_FIELD(arg0, s16 *, 0x32), arg0));
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80913CF8;
}
