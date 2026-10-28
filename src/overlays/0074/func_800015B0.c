// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6000844;
extern M2C_UNK D_80897CB4;

void func_800015B0(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6000844, 0xC0800000);
    func_800B8C4C(arg0, 0x3956);
    M2C_FIELD(arg0, s16 *, 0x2B2) = 0xFA0;
    M2C_FIELD(arg0, s16 *, 0x2B0) = 0xE;
    M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0xE);
    M2C_FIELD(arg0, u8 *, 0x421) = (u8) (M2C_FIELD(arg0, u8 *, 0x421) & 0xFFFE);
    M2C_FIELD(arg0, f32 *, 0x2C4) = 0.0f;
    if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
        M2C_FIELD(arg0, f32 *, 0x68) = 6.0f;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80897CB4;
}
