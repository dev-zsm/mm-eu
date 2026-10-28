// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80979BD4;
extern M2C_UNK D_8097C070;

void func_8000067C(u8 *arg0) {
    func_800BD9E0(arg0 + 0x144, &D_8097C070, 1, arg0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    func_800B8C4C(arg0, 0x3986);
    M2C_FIELD(arg0, s16 *, 0x3D0) = 0;
    M2C_FIELD(arg0, s16 *, 0x3DE) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_80979BD4;
}
