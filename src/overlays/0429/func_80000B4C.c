// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0429.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6001384;
extern M2C_UNK D_80AC4460;

void func_80000B4C(Actor *thisx) {
    func_801378E0((u8 *)thisx + 0x144, &D_6001384, thisx);
    M2C_FIELD(thisx, s8 *, 0x2AC) = 0;
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 0x10000);
    M2C_FIELD(thisx, M2C_UNK **, 0x2A8) = &D_80AC4460;
}
