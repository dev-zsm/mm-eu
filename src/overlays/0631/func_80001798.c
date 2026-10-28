// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BBB30(s32, u8 *, u8 *, M2C_UNK, s32, f32, s32, s32, s32); /* extern */
M2C_UNK func_80BF0030(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80BF18DC;

void func_80001798(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x2A4) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800B8C4C(arg0, 0x3AAA);
    M2C_FIELD(arg0, f32 *, 0x68) = 85.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -8.0f;
    func_80BF0030(arg0, 0xB);
    func_800BBB30(arg1, arg0, arg0 + 0x304, 0x40A00000, 0xA, 8.0f, 0x3E8, 0x64, 1);
    func_800BBB30(arg1, arg0, arg0 + 0x2F8, 0x40A00000, 0xA, 8.0f, 0x3E8, 0x64, 1);
    func_800B8C4C(arg0, 0x386C);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x08000000);
    M2C_FIELD(arg0, s16 *, 0x2B4) = 5;
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BF18DC;
}
