// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80100304(M2C_UNK *);                       /* extern */
extern M2C_UNK D_6000550;
extern M2C_UNK D_6000560;
extern s32 D_80B3512C;
extern s32 D_80B35130;

void func_800016D0(void) {
    D_80B35130 = func_80100304(&D_6000560);
    D_80B3512C = func_80100304(&D_6000550);
}
