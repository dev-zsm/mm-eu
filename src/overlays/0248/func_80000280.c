// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

f32 func_8008704C();                                /* extern */
s32 func_800B5B20(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
s8 func_800FF250(M2C_UNK, M2C_UNK);                 /* extern */
extern M2C_UNK D_80984ABC;
extern f32 D_80984B90;

void func_80000280(Actor *thisx, PlayState *play) {
    s8 temp_v0;

    if (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F, play) != 0) {
        M2C_FIELD(thisx, M2C_UNK **, 0x138) = &D_80984ABC;
        func_800F1944(M2C_FIELD(thisx, s8 *, 0x38));
        return;
    }
    temp_v0 = M2C_FIELD(thisx, s8 *, 0x144);
    if (temp_v0 >= 0) {
        if (temp_v0 == 0) {
            func_800B8C4C(thisx, 0x39DA);
            if (func_8008704C() < D_80984B90) {
                M2C_FIELD(thisx, s8 *, 0x144) = func_800FF250(0x28, 0x50);
                return;
            }
            M2C_FIELD(thisx, s8 *, 0x144) = 8;
            return;
        }
        M2C_FIELD(thisx, s8 *, 0x144) = (s8) (temp_v0 - 1);
    }
}
