#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0533.h"
s32 func_800A8670(s32 a);
void func_800A7C50(u8 *a, u8 *b, s32 c);

void func_80000584(u8 *a, u8 *play) {
    s32 r = func_800A8670(M2C_FIELD(a, s16 *, 0x1C) & 0x3F);

    if (r >= 0) {
        func_800A7C50(play, a + 0x24, (((M2C_FIELD(a, s16 *, 0x1C) >> 8) & 0x7F) << 8) | r);
    }
}
