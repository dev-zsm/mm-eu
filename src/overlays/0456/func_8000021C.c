#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0456.h"

extern M2C_UNK D_801E6EF0;

s32 func_8000021C(u8 *arg0) {
    switch ((M2C_FIELD(arg0, u16 *, 0x26E))) {
        case 0x14D0:
            return 0x14D1;
        case 0x14D1:
            if (M2C_FIELD(&D_801E6EF0, u8 *, 0x1010) & 0x80) {
            return 0x14E4;
            }
            if (M2C_FIELD(&D_801E6EF0, s16 *, 0x36) >= 0x31) {
            return 0x14D2;
            }
            M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
            return 0x14D3;
        case 0x14E4:
            if (M2C_FIELD(&D_801E6EF0, s16 *, 0x36) >= 0x31) {
            return 0x14D2;
            }
            M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
            return 0x14D3;
        case 0x14D2:
            if (M2C_FIELD(&D_801E6EF0, u8 *, 0x1010) & 0x80) {
            return 0x14E5;
            }
            return 0x14D4;
        case 0x14D4:
        case 0x14E5:
            return 0x14D5;
        case 0x14D8:
            return 0x14D9;
        case 0x14D9:
            return 0x14DA;
        default:
            return 0;
    }
}
