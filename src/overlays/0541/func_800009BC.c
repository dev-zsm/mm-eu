// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80B8ABB8;
extern M2C_UNK D_80B8CE60;

void func_800009BC(u8 *arg0) {
    func_800BD9E0(arg0 + 0x190, &D_80B8CE60, 2, arg0);
    M2C_FIELD(arg0, s16 *, 0x3F2) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, s16 *, 0x3F0) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B8ABB8;
}
