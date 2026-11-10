// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1F0]; s16 unk1F0; } S_arg0;

f32 func_8017A79C(f32);                             /* extern */
extern f32 D_80ADB268;

s16 func_800004E0(S_arg0 *arg0, s32 arg1) {
    return (s16) (s32) ((f32) M2C_FIELD(((u8 *)arg0 + (arg1 * 6)), s16 *, 0x1F6) * func_8017A79C((f32) (arg0->unk1F0 - (arg1 * 0x14)) * D_80ADB268));
}
