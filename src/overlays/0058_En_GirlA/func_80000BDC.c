// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0058.h"

M2C_UNK func_80112D7C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80115C10(s16);                         /* extern */

void EnGirlA_BuyBombchus(u8 *arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, s16 *, 0x1C2) == 0xA) {
        func_80112D7C(arg0, 0x98);
    }
    func_80115C10((s16) (M2C_FIELD(arg0, s32 *, 0x16978) * -1));
}
