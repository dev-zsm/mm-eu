// FLAGS: -O2 -g3 -mips2
#include "types.h"

s8 *Entrance_GetTableEntry(u16);

s8 Entrance_GetSceneId(u16 arg0) {
    return *Entrance_GetTableEntry(arg0);
}
