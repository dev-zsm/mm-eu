// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E10CC(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E7BB8(u8 *, u8 *);              /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80BBB000(u8 *);                      /* extern */
extern M2C_UNK D_6000148;
extern M2C_UNK D_80BBB240;
extern M2C_UNK D_80BBB274;

void func_80000360(Actor *thisx, PlayState *play) {
    u8 *sp24;
    u8 *temp_a1;

    func_800FF8DC(thisx, &D_80BBB274);
    func_800CABA0(thisx, 0);
    temp_a1 = (u8 *)thisx + 0x15C;
    sp24 = temp_a1;
    func_800E0F5C(play, temp_a1);
    if (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F) != 0) {
        func_800B6490(thisx);
        return;
    }
    func_800CABC4(play, thisx, &D_6000148);
    func_800E10CC(play, sp24, thisx, &D_80BBB240);
    func_800E7BB8(thisx, sp24);
    func_80BBB000(thisx);
}
