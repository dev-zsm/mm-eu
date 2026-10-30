// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800C9F3C(s32, s32, s32, s32, M2C_UNK *, u8 **); /* extern */
M2C_UNK func_800FF34C(u8 *, u8 *);              /* extern */
M2C_UNK func_80A75030(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_80A750F8;

void func_8000000C(Actor *thisx, PlayState *play) {
    s32 pad[2];
    u8 *sp2C;
    M2C_UNK sp28;

    if (func_800C9F3C(play, (u8 *)play + 0x830, M2C_FIELD(thisx, s32 *, 0x24), M2C_FIELD(thisx, s32 *, 0x2C), &sp28, &sp2C) == 0) {
        func_800B6490(thisx);
        return;
    }
    func_800FF34C((u8 *)thisx + 0x144, sp2C);
    M2C_FIELD(thisx, f32 *, 0x150) = (f32) M2C_FIELD(sp2C, s16 *, 6);
    M2C_FIELD(thisx, f32 *, 0x154) = (f32) M2C_FIELD(sp2C, s16 *, 8);
    func_80A75030(thisx, &D_80A750F8);
}
