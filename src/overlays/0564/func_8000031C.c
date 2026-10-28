// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7E1D;

s32 func_8000031C(u8 *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x33C);
    switch (temp_v0) {                              /* irregular */
    case 0x0:
        if (D_801E7E1D & 2) {
            M2C_FIELD(arg0, u16 *, 0x328) = (u16) (M2C_FIELD(arg0, u16 *, 0x328) | 1);
            return 0x1638;
        }
        return 0x162F;
    case 0x162F:
        return 0x1630;
    case 0x1630:
        return 0x1631;
    case 0x1631:
        M2C_FIELD(arg0, s16 *, 0x358) = 0x96;
        return 0x1632;
    case 0x1633:
        M2C_FIELD(arg0, s16 *, 0x358) = 0x64;
        return 0x1634;
    default:
        return 0;
    }
}
