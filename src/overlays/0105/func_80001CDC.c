// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0105.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE2EC(u8 *, s32);                 /* extern */
M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_6001F80;
extern M2C_UNK D_808C63AC;

void func_80001CDC(Actor *thisx) {
    func_801377D0((u8 *)thisx + 0x144, &D_6001F80);
    M2C_FIELD(thisx, f32 *, 0x70) = 10.0f;
    func_800BE2EC(thisx, (u8 *)thisx + 0x808);
    func_800BC8F4(thisx, 0x4000, 0xFF, 0, 0xF);
    func_800B8C4C(thisx, 0x3AB1);
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_808C63AC;
}
