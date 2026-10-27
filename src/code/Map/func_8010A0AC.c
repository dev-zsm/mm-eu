// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Map_GetMapIndexForOverworld();                                /* extern */

s32 Map_IsInOverworldSceneWithMapIndex(void) {
    if (Map_GetMapIndexForOverworld() == -1) {
        return 0;
    }
    return 1;
}
