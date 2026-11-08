// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0058.h"

M2C_UNK func_80112D7C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80115C10(s16);                         /* extern */

void EnGirlA_BuyShieldHero(PlayState *play, EnGirlA *this) {
    func_80112D7C(play, 0x51);
    func_80115C10((s16) (M2C_FIELD(play, s32 *, 0x16978) * -1));
}
