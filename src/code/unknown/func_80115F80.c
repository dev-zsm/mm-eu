// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern s16 D_801C03F0;
extern s16 D_801C03F4;
extern s16 D_801C03F8;
extern M2C_UNK D_801E6EF0;

void func_80115F80(s32 arg0) {
    if ((M2C_FIELD(&D_801E6EF0, s16 *, 0x3F28) != 8) && (M2C_FIELD(&D_801E6EF0, s16 *, 0x3F28) != 9)) {
        D_801C03F8 = 0xFF;
        D_801C03F4 = D_801C03F8;
        D_801C03F0 = D_801C03F4;
        M2C_FIELD(&D_801E6EF0, s16 *, 0x3F28) = 0;
    }
}
