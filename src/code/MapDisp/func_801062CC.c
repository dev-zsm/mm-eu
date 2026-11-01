// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 MapDisp_IsLocationRomaniRanchAltScene();                                /* extern */
s32 Map_IsInBossScene(void *);                          /* extern */
extern s32 D_801BF728;

s32 MapDisp_IsLocationMinimapBlocked(void *arg0) {
    if (((M2C_FIELD(arg0, u8 *, 0x1F2C) != 0) && (MapDisp_IsLocationRomaniRanchAltScene() == 0)) || (D_801BF728 & 2) || (Map_IsInBossScene(arg0) != 0)) {
        return 1;
    }
    return 0;
}
