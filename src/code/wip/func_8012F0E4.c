#include "types.h"

typedef struct {
    u8 pad0[0x6C];
    u16 equipment;
} SaveContext;

extern SaveContext D_801E6EF0;
extern u16 D_801C2A7A;
extern u8 D_801C2AC1;

void Inventory_ChangeEquipment(s16 value) {
    SaveContext *save = &D_801E6EF0;

    save->equipment = ((u16)value << D_801C2AC1) | (save->equipment & D_801C2A7A);
}
