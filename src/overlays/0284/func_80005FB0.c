#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809BB310;

void func_80005FB0(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x464) = &D_809BB310;
    M2C_FIELD(arg0, f32 *, 0x1C8) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, f32 *, 0xAC8) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x1C4) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = -15.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 12.0f;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
}
