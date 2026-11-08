// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0504.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E2500(s32, s32, u8 *);            /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
s8 func_800FF250(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK func_80B542D4(u8 *);                      /* extern */
extern f32 D_80B54780;

void BgKin2Picture_Wait(BgKin2Picture *this, PlayState *play) {
    s8 temp_v0_2;
    u8 temp_v0;

    temp_v0 = M2C_FIELD(this, u8 *, 0x16D);
    if (temp_v0 & 2) {
        M2C_FIELD(this, u8 *, 0x16D) = (u8) (temp_v0 & 0xFFFD);
        func_800F1944(M2C_FIELD(this, s8 *, 0x38));
        func_80B542D4(this);
        return;
    }
    temp_v0_2 = M2C_FIELD(this, s8 *, 0x242);
    if (temp_v0_2 >= 0) {
        if (temp_v0_2 == 0) {
            func_800B8C4C(this, 0x39DA);
            if (func_8008704C() < D_80B54780) {
                M2C_FIELD(this, s8 *, 0x242) = func_800FF250(0x28, 0x50);
            } else {
                M2C_FIELD(this, s8 *, 0x242) = 8;
            }
        } else {
            M2C_FIELD(this, s8 *, 0x242) = (s8) (temp_v0_2 - 1);
        }
    }
    func_800E2500(play, (u8 *)play + 0x18884, (u8 *)this + 0x15C);
}
