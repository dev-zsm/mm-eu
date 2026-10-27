#include "types.h"

extern s32 Map_IsInBossScene(void *a);
extern s32 MapData_GetMapIId(u16 a);
extern u8 **D_801BF708;

s32 MapDisp_CurRoomHasMapI(u8 *play) {
    s8 idx;
    u16 *p;

    if (Map_IsInBossScene(play) == 1) {
        return 1;
    }
    idx = *(s8 *)(play + 0x186E0);
    if (idx == -1) {
        return 0;
    }
    p = (u16 *)(*(u8 **)D_801BF708 + idx * 10);
    if (*p == 0xFFFF) {
        return 0;
    }
    if (MapData_GetMapIId(*p) == 0x3A) {
        return 0;
    }
    return 1;
}
