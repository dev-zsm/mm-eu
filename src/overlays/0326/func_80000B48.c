// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800FEA90(s32, M2C_UNK *, M2C_UNK);     /* extern */
s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK D_80A22FE0;

void func_80000B48(Actor *thisx, PlayState *play) {
    func_800FEA90((u8 *)thisx + 0x148, &D_80A22FE0, 0x70);
    M2C_FIELD(thisx, s16 *, 0x1C6) = func_800FF250(0, 0x3B);
    M2C_FIELD(thisx, s8 *, 0x1C4) = 0;
}
