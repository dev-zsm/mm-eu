// FLAGS: -O2 -g3 -mips2
#include "types.h"

s8 *Entrance_GetTableEntry(u16);

s32 Entrance_GetSceneId(u16 entrance) {
    return *Entrance_GetTableEntry(entrance);
}
