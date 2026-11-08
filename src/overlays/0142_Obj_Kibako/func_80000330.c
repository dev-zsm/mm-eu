// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0142.h"

M2C_UNK func_800E0FAC(M2C_UNK, s32, M2C_UNK, s32);  /* extern */

void ObjKibako_Destroy(Actor *thisx, PlayState *play2) {
    func_800E0FAC(play2, (u8 *)thisx + 0x148, play2, thisx);
}
