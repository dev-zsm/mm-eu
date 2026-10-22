// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Map_GetDungeonSceneIndexForDungeon();                                /* extern */

s32 Map_IsInDungeonScene(void) {
    if (Map_GetDungeonSceneIndexForDungeon() == -1) {
        return 0;
    }
    return 1;
}
