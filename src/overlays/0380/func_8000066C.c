#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A8D5D8[];
s32 func_800F1984(s16 a);
void func_800F1B24(s16 a, u8 *b);
void func_800F1944(s16 a);

void func_8000066C(u8 *a, s32 b) {
    s16 t = M2C_FIELD(a, s8 *, 0x38);

    if (func_800F1984(t) != 0) {
        func_800F1B24(t, a);
        M2C_FIELD(a, void **, 0x1A0) = D_80A8D5D8;
    } else {
        func_800F1944(t);
    }
}
