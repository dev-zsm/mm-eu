// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6001560;
extern M2C_UNK D_80B30594;

void func_80007E70(Actor *thisx) {
    func_80137828((u8 *)thisx + 0x144, &D_6001560, 0xC0C00000);
    M2C_FIELD(thisx, M2C_UNK **, 0x2EC) = &D_80B30594;
}
