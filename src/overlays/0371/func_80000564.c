#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0371.h"
s32 func_80A70778(u8 *a);
void func_80151E7C(u8 *a, u16 b);

s32 func_80000564(u8 *a, u8 *play, u8 *c) {
    if (~(M2C_FIELD(c, u16 *, 0xC) | ~0x4000) == 0) {
        M2C_FIELD(a, s32 *, 0x144) = M2C_FIELD(a, s32 *, 0x148);
        func_80151E7C(play, func_80A70778(a));
        return 1;
    }
    return 0;
}
