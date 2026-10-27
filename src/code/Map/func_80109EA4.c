// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapDisp_CurRoomHasMapI(s32);                             /* extern */
s32 Map_GetDungeonSceneIndex(s32);                             /* extern */

s32 Map_CurRoomHasMapI(s32 arg0) {
    if ((Map_GetDungeonSceneIndex(arg0) == -1) || (MapDisp_CurRoomHasMapI(arg0) == 0)) {
        return 0;
    }
    return 1;
}
