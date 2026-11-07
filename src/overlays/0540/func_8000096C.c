#include "types.h"
#include "m2c_compat.h"
s8 func_800F1E68(s16 a, u8 *b);
void func_800F1944(s8 a, u8 *b);
void func_800F1D6C(s16 a);

s32 func_8000096C(u8 *a, s32 b) {
    s16 t = M2C_FIELD(a, s8 *, 0x2B2);

    M2C_FIELD(a, s8 *, 0x2B2) = func_800F1E68(t, a);
    func_800F1944(M2C_FIELD(a, s8 *, 0x2B2), a);
    func_800F1D6C(t);
    return 0;
}
