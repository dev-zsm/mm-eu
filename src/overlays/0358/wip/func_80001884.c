#include "types.h"

s32 func_80001884(u8 *a0) {
    u8 *v0;

    v0 = *(u8 **)(a0 + 0x34C);
    if (v0 == 0 || *(s32 *)(v0 + 0x1E4) != 0) {
        v0 = 0;
        return 0;
    }
    *(s32 *)(v0 + 0x1E4) = 1;
    return 1;
}
