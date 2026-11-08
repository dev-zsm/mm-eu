// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0111.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6009900;
extern M2C_UNK D_808D58D0;

void func_8000234C(Actor *thisx) {
    M2C_FIELD(thisx, f32 *, 0xC4) = 0.0f;
    func_80137828((u8 *)thisx + 0x144, &D_6009900, 0xC0C00000, thisx);
    if (M2C_FIELD(thisx, u16 *, 0x90) & 1) {
        M2C_FIELD(thisx, f32 *, 0x70) = -2.0f;
    }
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 1);
    func_800B8C4C(thisx, 0x38E6);
    M2C_FIELD(thisx, s8 *, 0x3EF) = 0xB;
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_808D58D0;
}
