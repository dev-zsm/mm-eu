#include "types.h"

typedef struct {
    u32 **scenes;
    u32 pad4;
    u32 pad8;
} SceneEntranceTable;

extern SceneEntranceTable D_801C63E4[];

u32 *Entrance_GetTableEntry(u16 entrance) {
    u32 **sceneEntry = D_801C63E4[(u32)entrance >> 9].scenes;
    u32 *setup = sceneEntry[((u32)entrance >> 4) & 0x1F];

    return &setup[entrance & 0xF];
}
