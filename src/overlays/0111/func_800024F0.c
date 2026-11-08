// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0111.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6009298;
extern M2C_UNK D_808D5A58;

void func_800024F0(Actor *thisx) {
    func_80137828((u8 *)thisx + 0x144, &D_6009298, 0xBF800000, thisx);
    M2C_FIELD(thisx, s8 *, 0x3EF) = 0xC;
    M2C_FIELD(thisx, s16 *, 0x3D6) = 0x12C;
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    func_800B8C4C(thisx, 0x38E7);
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_808D5A58;
}
