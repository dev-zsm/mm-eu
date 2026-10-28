// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, u8 *, u8 *);      /* extern */
extern M2C_UNK D_808C2394;

void func_80000EF8(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s8 *, 0x24C) = 0;
    M2C_FIELD(arg0, f32 *, 0x26C) = 0.0f;
    func_800FF30C(arg0 + 0x24, arg0 + 8, arg0);
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + 50.0f);
    M2C_FIELD(arg0, s16 *, 0x250) = 0xC8;
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_808C2394;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
}
