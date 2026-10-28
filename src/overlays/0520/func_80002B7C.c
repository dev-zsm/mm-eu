// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

void func_80002B7C(void) {
    s32 temp_hi;

    temp_hi = (s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5;
    switch (temp_hi) {                              /* irregular */
    case 1:
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF05) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF05) | 4);
        return;
    case 2:
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF05) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF05) | 8);
        return;
    case 3:
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF05) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF05) | 0x10);
        return;
    }
}
