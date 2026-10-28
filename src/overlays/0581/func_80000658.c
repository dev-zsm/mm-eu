// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80BBD704;
extern M2C_UNK D_80BBE470;
extern M2C_UNK D_80BBF258;

void func_80000658(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80BBE470;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    func_800BD9E0(arg0 + 0x190, &D_80BBF258, 1, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80BBD704;
}
