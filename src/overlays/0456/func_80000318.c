// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_80000318(u8 *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x26E);
    switch (temp_v0) {                              /* irregular */
    case 0x14DC:
        M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
        return 0x14DD;
    case 0x14DD:
        return 0x14DE;
    case 0x14DE:
        M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF2E) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF2E) | 0x80);
        return 0x14DF;
    case 0x14E1:
        return 0x14E2;
    default:
        return 0;
    }
}
