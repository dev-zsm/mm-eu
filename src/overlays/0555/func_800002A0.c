#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0555.h"
s32 func_800F1E68(s16 a);

s32 func_800002A0(u8 *a, s32 n) {
    s16 v = M2C_FIELD(a, s8 *, 0x38);
    s32 i;

    for (i = 0; i < n; i++) {
        v = func_800F1E68(v);
    }
    return v;
}
