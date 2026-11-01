// FLAGS: -O2 -g3 -mips2
// STATUS: 8/31 instructions differ (register allocation of the save context base and the dungeon index)
#include "types.h"

typedef struct {
    u8 pad0[0xA4];
    s16 sceneId; /* 0xA4 */
} PlayState;

typedef struct {
    u8 pad0[0xC0];
    u8 dungeonItems[0x3F36 - 0xC0]; /* 0xC0 */
    u16 dungeonIndex;               /* 0x3F36 */
} SaveContext;

s32 Map_CurRoomHasMapI(PlayState *play);
s32 Inventory_IsMapVisible(s16 sceneId);
extern SaveContext D_801E6EF0;
extern u32 D_801C29F8;

s32 MapDisp_CanDisplayMinimap(PlayState *play) {
    if ((!Map_CurRoomHasMapI(play) && Inventory_IsMapVisible(play->sceneId)) ||
        (Map_CurRoomHasMapI(play) && (D_801C29F8 & D_801E6EF0.dungeonItems[D_801E6EF0.dungeonIndex]))) {
        return 1;
    }
    return 0;
}
