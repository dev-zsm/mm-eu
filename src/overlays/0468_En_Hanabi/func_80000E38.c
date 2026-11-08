// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0468.h"

M2C_UNK func_8018122C();                            /* extern */
M2C_UNK func_8018125C();                            /* extern */
M2C_UNK func_80B07CD8(s32, s32);                    /* extern */

void EnHanabi_Draw(Actor *thisx, PlayState *play) {
    func_8018122C();
    func_80B07CD8((u8 *)thisx + 0x148, play);
    func_8018125C();
}
