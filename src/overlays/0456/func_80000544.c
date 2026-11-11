#include "types.h"
#include "m2c_compat.h"

s32 func_80000544(u8 *arg0) {
    s32 temp_v0;

    switch ((M2C_FIELD(arg0, u16 *, 0x26E))) {
        case 0x14E6:
            temp_v0 = M2C_FIELD(arg0, u16 *, 0x26C);
            if (temp_v0 & 4) {
            return 0x14E7;
            }
            if (temp_v0 & 8) {
            return 0x14E9;
            }
        case 0x14E7:
            M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
            return 0x14E8;
        case 0x14E9:
            M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
            return 0x14EA;
        case 0x14EB:
            return 0x14EC;
        case 0x14EC:
            M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
            return 0x14ED;
        case 0x14EF:
            return 0x14F0;
        case 0x14F0:
            return 0x14F1;
        case 0x14F1:
            return 0x14F2;
        case 0x14F2:
            M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) | 2);
            return 0x14F3;
        default:
            return 0;
    }
}
