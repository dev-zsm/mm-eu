#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0371.h"
u16 func_80000388(u8 *a) {
    u8 *t = ((u8 **)(a + 0x340))[M2C_FIELD(a, u8 *, 0x34C)];

    if (M2C_FIELD(t, s16 *, 0x1C) == 2 && !(M2C_FIELD(a, u16 *, 0x42C) & 2)) {
        return 0x880;
    }
    return M2C_FIELD(t, u16 *, 0x116);
}
