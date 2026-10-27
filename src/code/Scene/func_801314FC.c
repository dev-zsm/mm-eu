#include "types.h"

f32 Scene_LagrangeInterp(s32 arg0, s32 arg1, s32 arg2, f32 arg3);

u8 Scene_LagrangeInterpColor(s32 arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 value = Scene_LagrangeInterp(arg0, arg1, arg2, arg3);
    s32 clamped;
    s32 color;

    if (value < 0) {
        color = 0;
    } else {
        if (value >= 0x100) {
            clamped = 0xFF;
        } else {
            clamped = value;
        }
        color = clamped;
    }
    return color;
}
