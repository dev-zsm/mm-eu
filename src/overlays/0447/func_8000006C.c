// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;
extern u16 D_801EC700;

s32 func_8000006C(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x38C);
    switch (temp_v0) {                              /* irregular */
    case 0:
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4E) & 1) {
            D_801EC700 = M2C_FIELD(&D_801E6EF0, u16 *, 0xC);
            M2C_FIELD(arg0, s32 *, 0x38C) = (s32) (M2C_FIELD(arg0, s32 *, 0x38C) + 1);
        }
        break;
    case 1:
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF51) & 8) {
            D_801EC700 = M2C_FIELD(&D_801E6EF0, u16 *, 0xC);
            M2C_FIELD(arg0, s32 *, 0x38C) = (s32) (M2C_FIELD(arg0, s32 *, 0x38C) + 1);
        }
        break;
    case 2:
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF51) & 0x40) {
            D_801EC700 = 0;
            M2C_FIELD(arg0, s32 *, 0x38C) = (s32) (M2C_FIELD(arg0, s32 *, 0x38C) + 1);
        }
        break;
    case 3:
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF52) & 1) {
            D_801EC700 = M2C_FIELD(&D_801E6EF0, u16 *, 0xC);
            M2C_FIELD(arg0, s32 *, 0x38C) = (s32) (M2C_FIELD(arg0, s32 *, 0x38C) + 1);
        }
        break;
    }
    return 1;
}
