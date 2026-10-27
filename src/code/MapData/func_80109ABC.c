#include "types.h"

extern s32 MapData_CPID_GetType(s32);
extern s32 MapData_GetSizeOfMapGrandTex(s32);
extern s32 MapDisp_GetSizeOfMapITex(s32);

s32 MapData_CPID_GetSizeOfMapTex(s32 id) {
    if (id == -1) {
        return 0;
    }
    switch (MapData_CPID_GetType(id)) {
        case 0:
            return MapData_GetSizeOfMapGrandTex(id + 0xC6);
        case 1:
            return MapDisp_GetSizeOfMapITex(id);
        case 2:
            return 0;
    }
    return 0;
}
