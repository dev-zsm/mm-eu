// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0134.h"

M2C_UNK func_800F1D6C(s8, u8 *);                  /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
extern M2C_UNK D_800BDD34;

void BgUmajump_StopCutscene(BgUmajump *this, PlayState *play) {
    if (((s32) M2C_FIELD(play, u16 *, 0x1F34) >= 6) && (M2C_FIELD(this, s32 *, 0x164) == 0)) {
        M2C_FIELD(this, s32 *, 0x164) = 1;
        func_8019FF78(0x2844);
    }
    if (M2C_FIELD(play, u8 *, 0x1F2C) == 0) {
        func_800F1D6C(M2C_FIELD(this, s8 *, 0x38), play);
        M2C_FIELD(this, M2C_UNK **, 0x138) = &D_800BDD34;
    }
}
