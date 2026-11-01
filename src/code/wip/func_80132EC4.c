#include "types.h"

extern s16 D_801E6F0A;

s32 Schedule_CheckNotInDayL(s32 play, u8 **scriptPtr, s32 result) {
    s32 ret = 0;
    u8 *script = *scriptPtr;
    s16 day = (script[1] << 8) | script[2];

    if (day != D_801E6F0A) {
        *scriptPtr = script + (s16)((script[3] << 8) | script[4]);
    }
    return ret;
}
