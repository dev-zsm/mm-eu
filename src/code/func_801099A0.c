#include "types.h"

extern s32 MapData_GetMapIId(s32 arg0);

s32 MapData_GetMapCompactId(s32 arg0) {
    s32 ret = MapData_GetMapIId(arg0);

    if (ret != 0x3A) {
        return ret;
    }
    if (arg0 >= 0x100 && arg0 < 0x162) {
        return arg0 - 0xC6;
    }
    return -1;
}
