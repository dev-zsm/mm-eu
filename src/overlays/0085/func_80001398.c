// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0085.h"

M2C_UNK func_8013C01C(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
M2C_UNK func_808A549C(u8 *);                      /* extern */
extern M2C_UNK D_808A6DAC;

void func_80001398(Actor *thisx) {
    func_8013C01C((u8 *)thisx + 0x144, &D_808A6DAC, 3, thisx);
    M2C_FIELD(thisx, f32 *, 0x2C8) = 1.0f;
    func_808A549C(thisx);
    M2C_FIELD(thisx, s16 *, 0x30C) = 0;
    M2C_FIELD(thisx, u16 *, 0x18C) = (u16) (M2C_FIELD(thisx, u16 *, 0x18C) & 0xFFEF);
    M2C_FIELD(thisx, f32 *, 0x2C8) = -1.0f;
    M2C_FIELD(thisx, f32 *, 0x2D4) = 0.0f;
    M2C_FIELD(thisx, f32 *, 0x2CC) = 0.0f;
    M2C_FIELD(thisx, f32 *, 0x2C4) = 1.0f;
}
