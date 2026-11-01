// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK KaleidoScopeCall_LoadPlayer();                            /* extern */
extern M2C_UNK (*D_801EE3C4)(s32, s32);

void PlayerCall_Destroy(s32 arg0, s32 arg1) {
    KaleidoScopeCall_LoadPlayer();
    D_801EE3C4(arg0, arg1);
}
