// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0540.h"

s32 func_800B8400(u8 *, s32);                     /* extern */
M2C_UNK func_80B88460(u8 *, s32, u8);             /* extern */
M2C_UNK func_80B885DC(u8 *, s32);                 /* extern */
M2C_UNK func_80B88A28(u8 *);                      /* extern */
M2C_UNK func_80B899E4(u8 *, s32);                 /* extern */

void func_80000604(Actor *thisx, PlayState *play) {
    func_80B885DC(thisx, play);
    func_80B88A28(thisx);
    if (func_800B8400(thisx, play) != 0) {
        func_80B88460(thisx, play, M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x2B8), u8 *, 1));
        return;
    }
    func_80B899E4(thisx, play);
}
