#include "types.h"
#include "generated/overlays/0606.h"
void func_8013AB70(void *, s32);
void func_800000B0(void *arg0, s32 arg1) {
    switch (arg1) {
        case 5:
        case 6:
        case 7:
        case 9:
            arg1 = 0xB;
            break;
        case 8:
            arg1 = 0xF;
            break;
        default:
            arg1 = -1;
            break;
    }
    func_8013AB70(arg0, arg1);
}
