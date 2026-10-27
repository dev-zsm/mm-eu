#include "types.h"

extern s32 MapData_CPID_GetType(s32);
extern void MapData_GetMapTexGameplayDangeonKeepOffset(s32);
extern void MapData_GetMapITexOffset(s32);

void MapData_CPID_GetTexOffset(s32 a0, s32 *a1, s32 *a2) {
    if (a0 == -1) {
        *a2 = 0;
        *a1 = 0;
        return;
    }
    switch (MapData_CPID_GetType(a0)) {
        case 0:
            MapData_GetMapTexGameplayDangeonKeepOffset(a0 + 0xC6);
            return;
        case 1:
            MapData_GetMapITexOffset(a0);
            return;
        case 2:
        default:
            *a2 = 0;
            *a1 = 0;
            break;
    }
}
