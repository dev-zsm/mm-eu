// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800F1EA8(s16, u8 *);                     /* extern */
extern M2C_UNK D_80A820B4;

void func_80002714(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x182) = func_800F1EA8(M2C_FIELD(arg0, s16 *, 0x186), arg0);
    if (M2C_FIELD(arg0, s16 *, 0x182) < 0) {
        M2C_FIELD(arg0, s16 *, 0x182) = 0x1E;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A820B4;
}
