// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0545.h"

s32 func_80147B34(s32);                             /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B95748(s32);                         /* extern */

void EnKujiya_FinishGivePrize(EnKujiya *this, PlayState *play) {
    if ((func_801529DC((u8 *)play + 0x4908) == 6) && (func_80147B34(play) != 0)) {
        func_80B95748(this);
    }
}
