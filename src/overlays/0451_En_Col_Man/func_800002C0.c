// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0451.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_80147B34(s32);                             /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_801E6EF0;

void EnColMan_SetHeartPieceCollectedAndKill(EnColMan *this, PlayState *play) {
    if ((func_801529DC((u8 *)play + 0x4908) == 6) && (func_80147B34(play) != 0)) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) | 2);
        func_800B6490(this);
    }
}
