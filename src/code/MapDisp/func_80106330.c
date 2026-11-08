// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapDisp_CanDisplayMinimap(s32);                             /* extern */
s32 MapDisp_IsLocationMinimapBlocked(s32);                             /* extern */

s32 MapDisp_IsMinimapToggleBlocked(struct PlayState *play) {
    if ((MapDisp_IsLocationMinimapBlocked(play) == 1) || (MapDisp_CanDisplayMinimap(play) == 0)) {
        return 1;
    }
    return 0;
}
