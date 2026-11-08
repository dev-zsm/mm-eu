#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0472.h"
void *func_800F1E3C(s16 a);
void func_800DF8D4(s32 a, s32 b);

void func_8000159C(u8 *a, u8 *play) {
    s8 v = M2C_FIELD(a, s8 *, 0x38);

    if (v != -1) {
        func_800DF8D4(M2C_FIELD(play, s32 *, 0x800), M2C_FIELD(func_800F1E3C(v), s16 *, 4));
    }
}
