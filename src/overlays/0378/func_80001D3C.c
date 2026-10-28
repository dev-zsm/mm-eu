// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A87490;

void func_80001D3C(u8 *arg0, u8 *arg1) {
    if ((M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) && ((s32) M2C_FIELD(arg1, u16 *, 0x1F34) >= 0x15)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80A87490;
    }
}
