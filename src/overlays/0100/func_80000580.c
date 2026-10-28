// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808BEC58();                            /* extern */
extern M2C_UNK D_808BEF10;

void func_80000580(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, u8 *, 0x394) = (u8) (M2C_FIELD(arg0, u8 *, 0x394) | 1);
    M2C_FIELD(arg0, u8 *, 0x395) = (u8) (M2C_FIELD(arg0, u8 *, 0x395) | 1);
    M2C_FIELD(arg0, u8 *, 0x396) = (u8) (M2C_FIELD(arg0, u8 *, 0x396) | 1);
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg0, f32 *, 0x68) = 17.0f;
    func_808BEC58();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    func_800B8C4C(arg0, 0x3A1C);
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_808BEF10;
}
