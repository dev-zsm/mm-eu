// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_80087010();                                /* extern */
f32 func_800C3EAC(s32, u8 *, M2C_UNK *, u8 *, u8 *); /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6000A20;
extern M2C_UNK D_80ABB60C;
extern M2C_UNK D_80ABBA40;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 pad[2];
    M2C_UNK sp2C;

    func_800FF8DC(thisx, &D_80ABBA40);
    func_800CABA0(thisx, 1);
    func_800CABC4(play, thisx, &D_6000A20);
    M2C_FIELD(thisx, f32 *, 0x88) = func_800C3EAC((u8 *)play + 0x830, (u8 *)thisx + 0x80, &sp2C, thisx, (u8 *)thisx + 0x24);
    M2C_FIELD(thisx, s16 *, 0x168) = 0x60;
    M2C_FIELD(thisx, s16 *, 0x32) = (s16) (func_80087010() >> 0x10);
    M2C_FIELD(thisx, M2C_UNK **, 0x15C) = &D_80ABB60C;
}
