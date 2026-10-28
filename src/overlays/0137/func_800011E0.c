// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809021B4();                            /* extern */
extern M2C_UNK D_80903370;

void func_800011E0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x270) = 0;
    M2C_FIELD(arg0, s16 *, 0x26A) = 0;
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    M2C_FIELD(arg0, f32 *, 0x78) = -10.0f;
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
    func_809021B4();
    M2C_FIELD(arg0, s32 *, 0x248) = 5;
    M2C_FIELD(arg0, M2C_UNK **, 0x23C) = &D_80903370;
    M2C_FIELD(arg0, s16 *, 0x240) = 0x12C;
    M2C_FIELD(arg0, f32 *, 0x24C) = 0.0f;
}
