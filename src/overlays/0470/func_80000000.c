// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800C9F3C(s32, s32, s32, s32, f32 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_80B091B0;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 pad[2];
    M2C_UNK sp2C;
    f32 sp28;

    func_800FF8DC(thisx, &D_80B091B0);
    if ((func_800C9F3C(play, (u8 *)play + 0x830, M2C_FIELD(thisx, s32 *, 0x24), M2C_FIELD(thisx, s32 *, 0x2C), &sp28, &sp2C) != 0) && (M2C_FIELD(thisx, f32 *, 0x28) < sp28)) {
        M2C_FIELD(thisx, s8 *, 0x144) = 1;
    }
}
