// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0242.h"

M2C_UNK func_801A26A4(s32, s8, u8 *);             /* extern */
extern M2C_UNK D_801E6EF0;

void ObjSound_Draw(Actor *thisx, PlayState *play) {
    if ((M2C_FIELD(&D_801E6EF0, u8 *, 0x1010) & 2) || (M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) & 0x20)) {
        func_801A26A4((u8 *)thisx + 0xEC, M2C_FIELD(thisx, s8 *, 0x1D), thisx);
    }
}
