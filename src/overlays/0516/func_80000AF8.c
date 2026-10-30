// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E10CC(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E7BB8(u8 *, u8 *);              /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
M2C_UNK func_80B69288(u8 *, s32);                 /* extern */
M2C_UNK func_80B6956C(u8 *, s32);                 /* extern */
extern M2C_UNK D_600B448;
extern M2C_UNK D_80B6A090;
extern M2C_UNK D_80B6A0C8;

void func_80000AF8(Actor *thisx, PlayState *play) {
    u8 *sp24;
    u8 *temp_a1;

    func_800FF8DC(thisx, &D_80B6A0C8);
    M2C_FIELD(thisx, s16 *, 0xC0) = 0;
    M2C_FIELD(thisx, s16 *, 0x34) = 0;
    temp_a1 = (u8 *)thisx + 0x144;
    sp24 = temp_a1;
    func_800E0F5C(play, temp_a1);
    func_800E10CC(play, temp_a1, thisx, &D_80B6A090);
    func_800E7BB8(thisx, temp_a1);
    M2C_FIELD(thisx, s32 *, 0x190) = func_80100304(&D_600B448);
    func_800B64E0(thisx, 0xC2C80000);
    func_80B69288(thisx, play);
    func_80B6956C(thisx, play);
}
