// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0262.h"

s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8B1C(s32, u8 *, f32, s16, f32);  /* extern */
extern u8 *D_801EB7E0;

void func_800002B0(Actor *thisx, PlayState *play) {
    s16 var_a3;

    if (func_800B7164(thisx, 0x4000) != 0) {
        var_a3 = M2C_FIELD(thisx, s16 *, 0xBE);
    } else {
        var_a3 = M2C_FIELD(thisx, s16 *, 0xBE) + 0x8000;
    }
    func_800B8B1C(play, thisx, (f32) M2C_FIELD(D_801EB7E0, s16 *, 0x1334) + 10.0f, var_a3, (f32) M2C_FIELD(D_801EB7E0, s16 *, 0x1336) + 5.0f);
}
