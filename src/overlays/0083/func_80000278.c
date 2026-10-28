// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808A2B78;

void func_80000278(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x190) == 4) {
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_808A2B78;
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    }
}
