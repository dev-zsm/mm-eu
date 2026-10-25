// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_801BFF04[];
extern s32 D_801BFB18[];

extern s32 MapData_MID_GetType(s32 index);

s32 MapData_GetMapIId(s32 index) {
    switch (MapData_MID_GetType(index)) {
        case 0:
            return D_801BFF04[index];
        case 1:
            return D_801BFB18[index];
        default:
            return 0;
    }
}
