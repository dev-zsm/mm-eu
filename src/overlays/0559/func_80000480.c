// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0559.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80BAA1A4;
extern M2C_UNK D_80BAB5A8;

void func_80000480(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x32C) = 0;
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 1);
    func_800BD9E0((u8 *)thisx + 0x1F0, &D_80BAB5A8, 8, thisx);
    M2C_FIELD(thisx, M2C_UNK **, 0x234) = &D_80BAA1A4;
}
