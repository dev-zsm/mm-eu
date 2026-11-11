#include "types.h"
#include "m2c_compat.h"

void func_80000188(s32 arg0, u8 *arg1, u8 *arg2) {
    s32 temp_v0;
    u8 *temp_v1;

    temp_v0 = arg0 << 6;
    M2C_FIELD((M2C_FIELD(arg1, s32 *, 0x1C) + temp_v0), s16 *, 0x30) = (s16) (s32) M2C_FIELD(arg2, f32 *, 0);
    M2C_FIELD((M2C_FIELD(arg1, s32 *, 0x1C) + temp_v0), s16 *, 0x32) = (s16) (s32) M2C_FIELD(arg2, f32 *, 4);
    M2C_FIELD((M2C_FIELD(arg1, s32 *, 0x1C) + temp_v0), s16 *, 0x34) = (s16) (s32) M2C_FIELD(arg2, f32 *, 8);
    temp_v1 = M2C_FIELD(arg1, s32 *, 0x1C) + temp_v0;
    M2C_FIELD(temp_v1, s16 *, 0x36) = (s16) (s32) ((f32) M2C_FIELD(temp_v1, s16 *, 0x2E) * M2C_FIELD(temp_v1, f32 *, 0x38));
}
