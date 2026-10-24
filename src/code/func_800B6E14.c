// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
extern f32 D_801D4AFC;
extern u8 *D_801EB7E0;
f32 func_800B6E14(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0xA6C);
    if (v & 0x800000) {
        return 15.0f;
    }
    if (v & 0x08000000) {
        return ((f32)*(s16 *)(D_801EB7E0 + 0x6E) / 100.0f) * D_801D4AFC;
    }
    return (f32)*(s16 *)(D_801EB7E0 + 0x6E) / 100.0f;
}
