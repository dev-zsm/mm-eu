#include "types.h"

typedef struct {
    u8 pad0[0xB8];
    u32 upgrades;
} SaveContext;

extern SaveContext D_801E6EF0;
extern u32 D_801C2AA0[];
extern u8 D_801C2AC4[];

void Inventory_ChangeUpgrade(s16 upgrade, s32 value) {
    SaveContext *save = &D_801E6EF0;
    u32 v = save->upgrades;

    v &= D_801C2AA0[upgrade];
    v |= value << D_801C2AC4[upgrade];
    save->upgrades = v;
}
