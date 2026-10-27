#include "types.h"

extern s32 MapData_CPID_GetType(s32);
extern void func_8010940C(s32, s32 *);
extern void func_801097DC(s32, s32 *);

void MapData_CPID_GetDrawType(s32 arg0, s32 *arg1) {
    if (arg0 == -1) {
        *arg1 = 0;
        return;
    }
    switch (MapData_CPID_GetType(arg0)) {
    case 0:
        func_8010940C(arg0 + 0xC6, arg1);
        return;
    case 1:
        func_801097DC(arg0, arg1);
        return;
    case 2:
        *arg1 = 0;
        break;
    default:
        *arg1 = 0;
        break;
    }
}
