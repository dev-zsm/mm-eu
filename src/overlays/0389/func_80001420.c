// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A98864;

void func_80001420(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x174) = &D_80A98864;
    M2C_FIELD(arg0, s16 *, 0x154) = 0;
    M2C_FIELD(arg0, s16 *, 0x156) = 0;
    M2C_FIELD(arg0, s16 *, 0x15E) = 0;
    M2C_FIELD(arg0, s16 *, 0x160) = 0;
    M2C_FIELD(arg0, s16 *, 0x162) = 0;
}
