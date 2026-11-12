#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, f32);             /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *, u8 *);      /* extern */
extern M2C_UNK D_8090DD5C;

void func_80001C1C(u8 *arg0) {
    s16 temp_v0;
    s16 temp_v1;

    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    func_800FF30C(arg0 + 0x24, arg0 + 8, arg0);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x14);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x16);
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s8 *, 0x197) = 0;
    M2C_FIELD(arg0, s16 *, 0xBC) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x30) = temp_v0;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v1;
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v1;
    func_800B6564(arg0, 0.0f);
    M2C_FIELD(arg0, s8 *, 0x194) = 0x7F;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8090DD5C;
}
