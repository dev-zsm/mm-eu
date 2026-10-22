// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Map_GetDungeonSceneIndexForBoss();                                /* extern */

s32 Map_IsInBossScene(void) {
    if (Map_GetDungeonSceneIndexForBoss() == -1) {
        return 0;
    }
    return 1;
}
