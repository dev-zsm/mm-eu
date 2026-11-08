// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0310.h"

M2C_UNK func_80137070(s32, s32);                    /* extern */

void func_80000154(Actor *thisx, PlayState *play) {
    func_80137070((u8 *)thisx + 0x148, thisx);
}
