#include "types.h"

typedef struct {
    u8 pad0[0x6C];
    u16 equipment;
} SaveContext;

typedef struct {
    u8 pad0[0x1CCC];
    void *player;
} PlayState;

extern SaveContext D_801E6EF0;
extern u16 D_801C2A72;
extern u8 D_801C2AC1;
extern u16 D_801C2A7A;

extern void Player_SetEquipmentData(PlayState *play, void *player);

s32 Inventory_DeleteEquipment(PlayState *play, s32 equipment) {
    u16 current = D_801E6EF0.equipment;

    if (((current & D_801C2A72) >> D_801C2AC1) != 0) {
        D_801E6EF0.equipment = (0 << D_801C2AC1) | (current & D_801C2A7A);
        Player_SetEquipmentData(play, play->player);
        return 1;
    }
    return 0;
}
