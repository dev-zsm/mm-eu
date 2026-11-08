// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapDisp_CurRoomHasMapI(s32);                             /* extern */
s32 Map_GetDungeonSceneIndex(s32);                             /* extern */

s32 Map_CurRoomHasMapI(struct PlayState *play) {
    if ((Map_GetDungeonSceneIndex(play) == -1) || (MapDisp_CurRoomHasMapI(play) == 0)) {
        return 0;
    }
    return 1;
}
