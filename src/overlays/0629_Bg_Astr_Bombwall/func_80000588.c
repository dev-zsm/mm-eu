// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0629.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800C604C(s32, s32, s32, s32);          /* extern */
M2C_UNK func_80BEEEC0(u8 *, s32);                 /* extern */
extern M2C_UNK D_80BEF25C;

void BgAstrBombwall_SetupCollapsing(BgAstrBombwall *this, PlayState *play) {
    func_800C604C(play, (u8 *)play + 0x880, M2C_FIELD(this, s32 *, 0x144), play);
    M2C_FIELD(this, s32 *, 0x13C) = 0;
    func_80BEEEC0(this, play);
    func_800B8C4C(this, 0x2810);
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80BEF25C;
}
