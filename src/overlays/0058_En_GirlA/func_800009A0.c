// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0058.h"

M2C_UNK func_80115C10(s16);                         /* extern */
M2C_UNK func_80115C38(M2C_UNK, s16, u8 *);        /* extern */

void EnGirlA_BuyArrows(PlayState *play, EnGirlA *this) {
    func_80115C38(1, M2C_FIELD(this, s16 *, 0x1C2), this);
    func_80115C10((s16) (M2C_FIELD(play, s32 *, 0x16978) * -1));
}
