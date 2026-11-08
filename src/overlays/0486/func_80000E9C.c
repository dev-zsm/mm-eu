#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0486.h"
s32 func_800F1984(s16 a);
void func_800F1A08(s16 a, u8 *b);
void func_800F1944(s16 a);

void func_80000E9C(u8 *a, s32 b) {
    s16 t = M2C_FIELD(a, s8 *, 0x38);

    if (func_800F1984(t) != 0) {
        func_800F1A08(t, a);
    } else {
        func_800F1944(t);
    }
}
