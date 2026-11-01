#include "types.h"
#include "generated/code_funcs.h"


void MapData_CPID_GetTexDim(s32 id, s32 *w, s32 *h) {
    if (id == -1) {
        *h = 0;
        *w = 0;
        return;
    }
    switch (MapData_CPID_GetType(id)) {
        case 0:
            MapData_GetMapTexGameplayDangeonKeepDim(id + 0xC6, w, h);
            break;
        case 1:
            MapData_GetMapITexDim(id, w, h);
            break;
        case 2:
        default:
            *h = 0;
            *w = 0;
            break;
    }
}
