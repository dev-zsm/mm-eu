#include "types.h"
#include "m2c_compat.h"
extern u8 D_801E7E1D;

u16 func_800003CC(u8 *a) {
    u8 *t = ((u8 **)(a + 0x340))[M2C_FIELD(a, u8 *, 0x34C)];

    if (M2C_FIELD(t, s16 *, 0x1C) == 2 && !(D_801E7E1D & 0x10)) {
        M2C_FIELD(a, u16 *, 0x406) = 0x881;
        return 0x881;
    }
    return M2C_FIELD(t, u16 *, 0x198);
}
