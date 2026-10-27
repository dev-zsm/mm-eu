#include "types.h"

extern s32 MapData_CPID_GetType(s32);
extern s32 MapData_MapGrandTexSizeTest(s32);
extern s32 MapData_MapITexSizeTest(s32);

s32 func_80109A38(s32 arg0) {
    if (arg0 == -1) {
        return 0;
    }
    switch (MapData_CPID_GetType(arg0)) {
    case 0:
        return MapData_MapGrandTexSizeTest(arg0 + 0xC6);
    case 1:
        return MapData_MapITexSizeTest(arg0);
    case 2:
        return 0;
    }
    return 0;
}
