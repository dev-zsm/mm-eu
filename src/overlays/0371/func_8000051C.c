#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0371.h"
void func_80A7080C(s32 a, s32 b, u8 *c);

s32 func_8000051C(s32 a, s32 b, u8 *c) {
    if (~(M2C_FIELD(c, u16 *, 0xC) | ~0x4000) == 0) {
        func_80A7080C(b, a, c);
        return 1;
    }
    return 0;
}
