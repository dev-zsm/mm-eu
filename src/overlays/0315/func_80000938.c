// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800FEA90(s32, M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK D_80A192C0;

void func_80000938(Actor *thisx, PlayState *play) {
    func_800FEA90((u8 *)thisx + 0x148, &D_80A192C0, 0xE0, thisx);
}
