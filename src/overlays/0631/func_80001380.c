// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80BF0030(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80BF1448;

void func_80001380(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x2A4) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_80BF0030(arg0, 2);
    func_800B8C4C(arg0, 0x3AA5);
    M2C_FIELD(arg0, s16 *, 0x294) = 0;
    if (M2C_FIELD(arg0, s32 *, 0x2DC) != 0) {
        M2C_FIELD(arg0, s16 *, 0x294) = 0x28;
        func_800B8C4C(arg0, 0x389E);
        func_800BC8F4(arg0, 0, 0xFF, 0, 0x28);
    }
    M2C_FIELD(arg0, s16 *, 0x2B4) = 3;
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BF1448;
}
