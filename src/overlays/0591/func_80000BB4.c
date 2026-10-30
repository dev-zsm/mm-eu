// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6564(u8 *, f32);                 /* extern */
M2C_UNK func_800B6730(u8 *);                      /* extern */
M2C_UNK func_800B6838(u8 *);                      /* extern */
extern u8 *D_801EB7E0;
extern f32 D_80BC9650;
extern f32 D_80BC9654;

void func_80000BB4(Actor *thisx, PlayState *play) {
    s16 temp_a0;
    s32 var_v1;
    u8 *var_v0;

    func_800B6564(thisx, ((f32) M2C_FIELD(D_801EB7E0, s16 *, 0x9F4) * D_80BC9650) + D_80BC9654);
    var_v1 = 0;
    if (M2C_FIELD(D_801EB7E0, s16 *, 0xA52) == 0) {
        var_v0 = thisx;
        M2C_FIELD(thisx, s16 *, 0x144) = (s16) (M2C_FIELD(thisx, s16 *, 0x144) + 1);
        do {
            temp_a0 = M2C_FIELD(var_v0, s16 *, 0x146);
            var_v1 += 2;
            if (temp_a0 != 0) {
                M2C_FIELD(var_v0, s16 *, 0x146) = (s16) (temp_a0 - 1);
            }
            var_v0 += 2;
        } while (var_v1 != 4);
        M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x22C)(thisx, play);
        func_800B6838(thisx);
        func_800B6730(thisx);
    }
}
