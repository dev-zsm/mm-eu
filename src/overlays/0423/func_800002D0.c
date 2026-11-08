// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0423.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6004210;
extern M2C_UNK D_80ABBE1C;

void func_800002D0(Actor *thisx) {
    func_80137828((u8 *)thisx + 0x144, &D_6004210, 0xC0A00000, thisx);
    M2C_FIELD(thisx, M2C_UNK **, 0x298) = &D_80ABBE1C;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
}
