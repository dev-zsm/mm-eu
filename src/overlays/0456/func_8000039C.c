#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_8000039C(u8 *arg0) {
    switch ((M2C_FIELD(arg0, u16 *, 0x26E))) {
        case 0x14F5:
            return 0x14F6;
        case 0x14F6:
            return 0x14F7;
        case 0x14F7:
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF44) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF44) | 0x80);
            M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
            return 0x14F8;
        case 0x14F9:
            return 0x14FA;
        case 0x14FA:
            M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
            return 0x14FB;
        default:
            return 0;
    }
}
