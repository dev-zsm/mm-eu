// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0633.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_801377D0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6000088;
extern M2C_UNK D_80BF6AB4;

void func_800014F0(Actor *thisx) {
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    M2C_FIELD(thisx, f32 *, 0x68) = 0.0f;
    func_801377D0((u8 *)thisx + 0x144, &D_6000088);
    M2C_FIELD(thisx, u16 *, 0x90) = (u16) (M2C_FIELD(thisx, u16 *, 0x90) & 0xFFFE);
    M2C_FIELD(thisx, s16 *, 0xBC) = 0;
    M2C_FIELD(thisx, s16 *, 0x18E) = 0x28;
    M2C_FIELD(thisx, f32 *, 0x68) = 0.0f;
    func_800B8C4C(thisx, 0x3A99);
    func_800BC8F4(thisx, 0x4000, 0xFF, 0, 0x28);
    M2C_FIELD(thisx, u8 *, 0x281) = (u8) (M2C_FIELD(thisx, u8 *, 0x281) & 0xFFFE);
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 0x10);
    M2C_FIELD(thisx, s16 *, 0x192) = 0x1C00;
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80BF6AB4;
}
