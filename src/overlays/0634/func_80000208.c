// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0FAC(M2C_UNK, s32, s32, M2C_UNK);  /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000208(s32 arg0, M2C_UNK arg1) {
    func_800E0FAC(arg1, arg0 + 0x144, arg0, arg1);
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF52) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF52) & 0xDF);
}
