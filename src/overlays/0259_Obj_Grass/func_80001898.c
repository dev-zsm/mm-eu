// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0259.h"

M2C_UNK func_8098EFB8(s32, s32);                    /* extern */
M2C_UNK func_8098F28C(s32, s32);                    /* extern */
M2C_UNK func_8098F4D8(s32, s32);                    /* extern */

void ObjGrass_Draw(Actor *thisx, PlayState *play) {
    func_8098EFB8(thisx, play);
    func_8098F28C(thisx, play);
    func_8098F4D8(thisx, play);
}
