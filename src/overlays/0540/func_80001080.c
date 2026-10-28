// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_80001080(s32 arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, u16 *, 0x16936) == 4) {
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) == 4) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) | 0x10);
        }
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) == 3) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) | 0x20);
        }
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) == 2) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) | 0x40);
        }
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) == 1) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) | 0x80);
        }
        return 1;
    }
    return 0;
}
