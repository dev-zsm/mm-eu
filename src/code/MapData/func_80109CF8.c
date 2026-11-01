#include "types.h"
#include "generated/code_funcs.h"


s32 MapData_CPID_GetMapColorIndex(s32 cpid) {
    if (cpid == -1) {
        return 0;
    }
    switch (MapData_CPID_GetType(cpid)) {
        case 0:
            return MapData_GetMapGrandColorIndex(cpid + 0xC6);
        case 1:
            return MapData_GetMapIColorIndex(cpid);
        case 2:
            break;
    }
    return 0;
}
