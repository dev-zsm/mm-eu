// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E10CC(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E7BB8(u8 *, u8 *);              /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
M2C_UNK func_80BBA238(u8 *);                      /* extern */
M2C_UNK func_80BBA2A0(u8 *);                      /* extern */
extern M2C_UNK D_6001228;
extern M2C_UNK D_80BBA390;
extern M2C_UNK D_80BBA3BC;

void func_80000000(Actor *thisx, PlayState *play) {
    u8 *sp24;
    u8 *temp_a1;

    func_800FF8DC(thisx, &D_80BBA3BC);
    temp_a1 = (u8 *)thisx + 0x144;
    sp24 = temp_a1;
    func_800E0F5C(play, temp_a1);
    func_800E10CC(play, temp_a1, thisx, &D_80BBA390);
    func_800E7BB8(thisx, temp_a1);
    M2C_FIELD(thisx, s32 *, 0x190) = func_80100304(&D_6001228);
    if (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F) != 0) {
        func_80BBA2A0(thisx);
        return;
    }
    func_80BBA238(thisx);
}
