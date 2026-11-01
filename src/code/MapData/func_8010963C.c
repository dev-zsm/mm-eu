#include "types.h"
#include "generated/code_funcs.h"


void MapData_GetMapScale(s32 a0, s32 *scale) {
    switch (MapData_MID_GetType(a0)) {
        default:
            *scale = 0;
            break;
        case 0:
            *scale = MapData_GetMapGameplayDangeonKeepScale(a0);
            break;
        case 1:
            *scale = MapData_GetMapGrandScale(a0);
            break;
    }
}
