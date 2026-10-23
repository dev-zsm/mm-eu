// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void MapDisp_InitChestData();

void Scene_CommandMapDataChests(s32 a0, u8 *a1) {
    u8 *a3 = a1;

    MapDisp_InitChestData(a0, a3[1], *(s32 *)(a3 + 4));
}
