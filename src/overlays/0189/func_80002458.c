// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809567A4;

void func_80002458(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x116) = 0x164D;
    M2C_FIELD(arg0, s16 *, 0x196) = 7;
    M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_809567A4;
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
}
