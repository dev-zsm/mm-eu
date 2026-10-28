// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80087010();                                /* extern */
f32 func_800C3EAC(s32, u8 *, M2C_UNK *, u8 *, u8 *); /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6000A20;
extern M2C_UNK D_80ABB60C;
extern M2C_UNK D_80ABBA40;

void func_80000000(u8 *arg0, s32 arg1) {
    s32 pad[2];
    M2C_UNK sp2C;

    func_800FF8DC(arg0, &D_80ABBA40);
    func_800CABA0(arg0, 1);
    func_800CABC4(arg1, arg0, &D_6000A20);
    M2C_FIELD(arg0, f32 *, 0x88) = func_800C3EAC(arg1 + 0x830, arg0 + 0x80, &sp2C, arg0, arg0 + 0x24);
    M2C_FIELD(arg0, s16 *, 0x168) = 0x60;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (func_80087010() >> 0x10);
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80ABB60C;
}
