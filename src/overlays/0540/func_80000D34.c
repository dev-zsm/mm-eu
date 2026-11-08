// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0540.h"

M2C_UNK func_800B701C(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_80122C10(s32, s32, M2C_UNK);               /* extern */
M2C_UNK func_80B88A28(s32);                         /* extern */
s32 func_80B88FA4(s32, s32);                        /* extern */

s32 func_80000D34(s32 arg0, PlayState *play) {
    func_80B88A28(arg0);
    if (func_80122C10(play, arg0 + 0x2BC, 0x42700000) != 0) {
        func_800B701C(play, 0, 0x13);
        return func_80B88FA4(arg0, play);
    }
    return 0;
}
