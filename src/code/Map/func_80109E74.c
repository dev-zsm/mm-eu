// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s32 Map_GetDungeonSceneIndex();                                /* extern */

s32 Map_IsInDungeonOrBossScene(void) {
    if (Map_GetDungeonSceneIndex() == -1) {
        return 0;
    }
    return 1;
}
