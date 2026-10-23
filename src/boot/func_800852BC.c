// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 PadUtils_GetCurX(s32);
s32 PadUtils_GetCurY(s32);
void PadUtils_SetRelXY(s32, s32, s32);

void PadUtils_UpdateRelXY(s32 input) {
    s32 curX = PadUtils_GetCurX(input);
    s32 curY = PadUtils_GetCurY(input);
    s32 relX;
    s32 relY;

    if (curX > 7) {
        if (curX < 67) {
            relX = curX - 7;
        } else {
            relX = 60;
        }
    } else if (curX < -7) {
        if (curX > -67) {
            relX = curX + 7;
        } else {
            relX = -60;
        }
    } else {
        relX = 0;
    }
    if (curY > 7) {
        if (curY < 67) {
            relY = curY - 7;
        } else {
            relY = 60;
        }
    } else if (curY < -7) {
        if (curY > -67) {
            relY = curY + 7;
        } else {
            relY = -60;
        }
    } else {
        relY = 0;
    }
    PadUtils_SetRelXY(input, relX, relY);
}
