// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80B8B468;
extern M2C_UNK D_80B8CE60;

void func_80001264(u8 *arg0) {
    func_800BD9E0(arg0 + 0x190, &D_80B8CE60, 6, arg0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    func_800B8C4C(arg0, 0x38E7);
    M2C_FIELD(arg0, s16 *, 0x3F2) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B8B468;
}
