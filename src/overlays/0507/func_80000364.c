#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0507.h"
s8 func_800F1E68(s8 a, u8 *b);

s8 func_80000364(u8 *a) {
    s16 d = M2C_FIELD(a, s16 *, 0x92) - M2C_FIELD(a, s16 *, 0xBE);

    if (d > 0) {
        return M2C_FIELD(a, s8 *, 0x38);
    }
    return func_800F1E68(M2C_FIELD(a, s8 *, 0x38), a);
}
