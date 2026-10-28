// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8011489C(M2C_UNK, u8);                 /* extern */
extern u8 D_801C2D64;

s32 func_800003DC(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C) & 3;
    switch (temp_v0) {                              /* irregular */
    case 0:
        return 0x98;
    case 1:
        return 0x99;
    case 2:
        return 0x9A;
    case 3:
        func_8011489C(0x2C, D_801C2D64);
        return 7;
    default:
        return 0;
    }
}
