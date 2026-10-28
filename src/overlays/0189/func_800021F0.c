// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7E37;
extern u8 *D_801EB7E0;
extern M2C_UNK D_8095659C;

void func_800021F0(u8 *arg0, u8 *arg1) {
    if ((D_801E7E37 & 8) && (M2C_FIELD(arg0, f32 *, 0x98) < M2C_FIELD(arg0, f32 *, 0x250)) && ((M2C_FIELD(D_801EB7E0, s16 *, 0x12D6) != 0) || (M2C_FIELD(arg1, u16 *, 0x16936) == 0xD))) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xF7FFFFFF);
        M2C_FIELD(arg1, u16 *, 0x16936) = 4U;
        M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_8095659C;
    }
}
