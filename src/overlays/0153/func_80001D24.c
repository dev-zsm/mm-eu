// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8091BC20();                            /* extern */
extern M2C_UNK D_8091D54C;

void func_80001D24(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    M2C_FIELD(arg0, s16 *, 0x1B2) = 0x64;
    func_8091BC20();
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_8091D54C;
}
