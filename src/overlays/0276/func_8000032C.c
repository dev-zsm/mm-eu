// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809AEAF4;

void func_8000032C(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x98) < 60.0f) {
        M2C_FIELD(arg0, s16 *, 0x162) = 0xA;
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809AEAF4;
    }
}
