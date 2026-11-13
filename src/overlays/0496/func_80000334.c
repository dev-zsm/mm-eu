#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x24]; f32 unk24; u8 pad28[0x4]; f32 unk2C; u8 pad30[0x8E]; s16 unkBE; u8 padC0[0x154]; f32 unk214; } S_arg0;

f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */

void func_80000334(S_arg0 *arg0) {
    f32 *temp_s3;
    s8 *var_s1;
    s32 var_s2;

    var_s2 = 0;
    var_s1 = (u8 *)arg0 + 0x338;
    do {
        temp_s3 = var_s1;
        M2C_FIELD(var_s1, f32 *, 0) = (func_800FEB84(arg0->unkBE) * arg0->unk214) + arg0->unk24;
        M2C_FIELD(temp_s3, f32 *, 8) = (f32) ((func_800FEB44(arg0->unkBE) * arg0->unk214) + arg0->unk2C);
        var_s2 += 0x20;
        var_s1 += 0x20;
        arg0->unkBE = (s16) (arg0->unkBE + 0x5555);
    } while (var_s2 != 0x60);
}
