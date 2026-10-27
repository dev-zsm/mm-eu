// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapData_CPID_GetType(s32 mapId);
s32 MapData_GetMapGrandScale(s32 mapId);
s32 MapData_GetMapIScale(s32 mapId);

s32 MapData_CPID_GetMapScale(s32 mapId) {
    if (mapId == -1) {
        return 0;
    }
    switch (MapData_CPID_GetType(mapId)) {
        case 0:
            return MapData_GetMapGrandScale(mapId + 0xC6);
        case 1:
            return MapData_GetMapIScale(mapId);
        case 2:
            break;
    }
    return 0;
}
