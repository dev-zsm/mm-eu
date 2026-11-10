#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x30]; s16 unk30; s16 unk32; u8 pad34[0x30]; f32 unk64; f32 unk68; f32 unk6C; f32 unk70; } S_arg0;

M2C_UNK func_800B6730(u8 *);                      /* extern */
f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */

void func_80000000(S_arg0 *arg0, s16 arg1) {
    f32 sp24;

    sp24 = func_800FEB44(arg0->unk30) * arg0->unk70;
    arg0->unk64 = (f32) (func_800FEB84(arg0->unk32) * sp24);
    arg0->unk68 = (f32) (func_800FEB84(arg0->unk30) * arg0->unk70);
    arg0->unk6C = (f32) (func_800FEB44(arg0->unk32) * sp24);
    if (arg1 != 0) {
        arg0->unk64 = 0.0f;
        arg0->unk6C = 0.0f;
    }
    func_800B6730(arg0);
}
