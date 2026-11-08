#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0475.h"
s32 func_80B10A28(u8 *a, u8 *b);

s32 func_80000500(u8 *a, u8 *play, u8 *c) {
    s32 r = 0;

    M2C_FIELD(a, s16 *, 0x208) = 0;
    switch (*c) {
        case 1:
            r = func_80B10A28(a, play);
            break;
        case 2:
            r = 1;
            break;
    }
    return r;
}
