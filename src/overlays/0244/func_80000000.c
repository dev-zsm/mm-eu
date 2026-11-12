// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "m2c_compat.h"

typedef struct { f32 unk0; u8 pad4[0x4]; f32 unk8; } S_arg0;

f32 func_800FEB44();                             /* extern */
f32 func_800FEB84();                             /* extern */

void func_80000000(S_arg0 *arg0, s16 arg1) {
    f32 sp24;
    f32 sp20;

    sp20 = func_800FEB44(arg1);
    sp24 = (func_800FEB84(arg1) * arg0->unk8) + (sp20 * arg0->unk0);
    sp20 = func_800FEB84(arg1);
    arg0->unk8 = (f32) ((func_800FEB44(arg1) * arg0->unk8) + (-sp20 * arg0->unk0));
    arg0->unk0 = sp24;
}
