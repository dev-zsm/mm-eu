// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapDisp_CanDisplayMinimap(s32);                             /* extern */
s32 MapDisp_IsLocationMinimapBlocked(s32);                             /* extern */

s32 MapDisp_IsMinimapToggleBlocked(s32 arg0) {
    if ((MapDisp_IsLocationMinimapBlocked(arg0) == 1) || (MapDisp_CanDisplayMinimap(arg0) == 0)) {
        return 1;
    }
    return 0;
}
