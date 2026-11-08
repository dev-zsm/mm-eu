// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0164.h"

s32 func_800B5B20(M2C_UNK, s16, M2C_UNK);           /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
extern M2C_UNK D_8092B1E0;

void ObjBlockstop_Init(Actor *thisx, PlayState *play) {
    if (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x1C), play) != 0) {
        func_800B6490(thisx);
    }
    M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_8092B1E0;
}
