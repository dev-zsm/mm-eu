// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B668C0;

void func_800018A4(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x584) = 0x2001;
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B668C0;
}
