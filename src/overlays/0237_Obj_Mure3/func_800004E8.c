// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0237.h"

s32 func_800B5B20(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_809742D8(u8 *);                      /* extern */
extern M2C_UNK D_80974488;

void ObjMure3_Init(Actor *thisx, PlayState *play) {
    if (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F, play) != 0) {
        func_800B6490(thisx);
        return;
    }
    func_800FF8DC(thisx, &D_80974488);
    func_809742D8(thisx);
}
