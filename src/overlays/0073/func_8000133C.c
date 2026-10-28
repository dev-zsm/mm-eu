// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BE2EC(u8 *, u8 *);              /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60012E4;
extern M2C_UNK D_808942E8;

void func_8000133C(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_60012E4, 0x40800000, arg0);
    M2C_FIELD(arg0, f32 *, 0x70) = -6.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    if (M2C_FIELD(arg0, s32 *, 0x3B4) != 0) {
        func_800BE2EC(arg0, arg0 + 0x3AC);
    } else {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    }
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0x32) + 0x8000);
    M2C_FIELD(arg0, M2C_UNK **, 0x2B4) = &D_808942E8;
}
