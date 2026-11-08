// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0417.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_800C5F18(u8 *, u8 *, u8 *, s32);     /* extern */
M2C_UNK func_800C92F4(M2C_UNK *, s32 *);            /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1F14(u8 *, u8 *);              /* extern */
M2C_UNK func_800E1FB4(u8 *, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80AB46C4(u8 *);                      /* extern */
extern M2C_UNK D_60015C0;
extern M2C_UNK D_80AB5320;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 pad[2];
    s32 sp34;
    u8 *temp_s0;
    u8 *var_s0;

    sp34 = 0;
    var_s0 = M2C_FIELD(play, u8 **, 0x1CE4);
    func_800CABA0(thisx, 1);
    func_800C92F4(&D_60015C0, &sp34);
    M2C_FIELD(thisx, s32 *, 0x144) = func_800C5F18(play, (u8 *)play + 0x880, thisx, sp34);
    func_800B6564(thisx, 0x3DCCCCCD);
    if (var_s0 != NULL) {
loop_1:
        if (M2C_FIELD(var_s0, s16 *, 0) == 0xB5) {
            M2C_FIELD(thisx, u8 **, 0x120) = var_s0;
        } else {
            var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
            if (var_s0 != NULL) {
                goto loop_1;
            }
        }
    }
    if (var_s0 == NULL) {
        func_800B6490(thisx);
        return;
    }
    temp_s0 = (u8 *)thisx + 0x160;
    func_800E1F14(play, temp_s0);
    func_800E1FB4(play, temp_s0, thisx, &D_80AB5320);
    M2C_FIELD(thisx, s16 *, 0x1AE) = 0xA;
    M2C_FIELD(thisx, s16 *, 0x33A) = 0;
    M2C_FIELD(thisx, s16 *, 0x33C) = 0;
    M2C_FIELD(thisx, s8 *, 0xB7) = 1;
    func_80AB46C4(thisx);
}
