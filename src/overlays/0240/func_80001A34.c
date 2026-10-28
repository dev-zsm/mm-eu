// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_800F0308(s32, u8 *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_8097AFC4;
extern M2C_UNK D_8097C070;

void func_80001A34(u8 *arg0, s32 arg1) {
    func_800BD9E0(arg0 + 0x144, &D_8097C070, 4);
    M2C_FIELD(arg0, s16 *, 0x3D8) = (s16) (M2C_FIELD(arg0, s16 *, 0x3D8) | 0x40);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, f32 *, 0x70) = -6.0f;
    }
    M2C_FIELD(arg0, s8 *, 0x3E4) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    func_800F0308(arg1, arg0 + 0x24, 0x28, 0x3833);
    M2C_FIELD(arg0, s16 *, 0x3DE) = 7;
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_8097AFC4;
}
