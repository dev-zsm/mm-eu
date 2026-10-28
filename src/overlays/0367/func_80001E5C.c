// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A634A0;

void func_80001E5C(u8 *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x1BC0), s16 *, 0x2E) = 0x28;
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x1BC0), s16 *, 0x6E) = 0x28;
    M2C_FIELD(arg0, s32 *, 0x38C) = 0;
    M2C_FIELD(arg0, s16 *, 0x2B2) = 6;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80A634A0;
}
