// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Lights_GlowCheck(s32);                         /* extern */
s32 func_80179CA8(s32, s32);                        /* extern */
extern s32 D_801BE6E4;
extern s32 D_801EC7A8;
extern s32 D_801EC7AC;

void Environment_GraphCallback(s32 arg0, s32 arg1) {
    D_801BE6E4 = func_80179CA8(D_801EC7A8, D_801EC7AC);
    Lights_GlowCheck(arg1);
}
