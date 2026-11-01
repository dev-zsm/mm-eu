#include "types.h"

extern void func_8010EE64(s32 arg0);

s16 CutsceneManager_SetHudVisibility(s16 arg) {
    s16 x;

    x = arg;
    switch (x) {
        case 0:
            x = 2;
            break;
        case 1:
            x = 0x32;
            break;
        case 2:
            x = 5;
            break;
        case 3:
            x = 0xE;
            break;
        case 4:
            x = 0xF;
            break;
        case 5:
            x = 0x10;
            break;
        case 6:
            x = 0x11;
            break;
        case 7:
            x = 4;
            break;
        default:
            x = 0x32;
            break;
    }
    func_8010EE64(x);
    return (u16)x;
}
