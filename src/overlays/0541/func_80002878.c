#include "types.h"
#include "m2c_compat.h"

void func_80002878(u8 *arg0) {
    switch ((M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F)) {
        case 1:
            M2C_FIELD(arg0, s16 *, 0x3FC) = 0x207;
            return;
        case 2:
            M2C_FIELD(arg0, s16 *, 0x3FC) = 0x208;
            return;
        case 3:
            M2C_FIELD(arg0, s16 *, 0x3FC) = 0x209;
            return;
        case 4:
            M2C_FIELD(arg0, s16 *, 0x3FC) = 0x20A;
            return;
        case 5:
            M2C_FIELD(arg0, s16 *, 0x3FC) = 0x20B;
            return;
        default:
            M2C_FIELD(arg0, s16 *, 0x3FC) = 0x207;
            return;
    }
}
