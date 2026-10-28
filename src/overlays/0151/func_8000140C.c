// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809183D0;

void func_8000140C(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0xBD6) = 1;
    M2C_FIELD(arg0, s16 *, 0xBCA) = 0x28;
    M2C_FIELD(arg0, s8 *, 0xBCC) = 1;
    M2C_FIELD(arg0, s8 *, 0xBCE) = 1;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809183D0;
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
}
