// FLAGS: -O2 -g3 -mips2
// STATUS: automatic draft, 12/28 instructions differ
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

void func_8012F56C(s16 arg0) {
    if (arg0 == 0x27) {
        M2C_FIELD(&D_801E6EF0, s32 *, 0xEC0) = (s32) (((((u32) (M2C_FIELD(&D_801E6EF0, s32 *, 0xEC0) & 0xFFFF0000) >> 0x10) + 1) << 0x10) | (M2C_FIELD(&D_801E6EF0, s32 *, 0xEC0) & 0xFFFF));
        return;
    }
    M2C_FIELD(&D_801E6EF0, s32 *, 0xEC0) = (s32) (((M2C_FIELD(&D_801E6EF0, s32 *, 0xEC0) + 1) & 0xFFFF) | (M2C_FIELD(&D_801E6EF0, s32 *, 0xEC0) & 0xFFFF0000));
}
