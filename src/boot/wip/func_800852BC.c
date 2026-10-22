// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 PadUtils_GetCurX(s32);
s32 PadUtils_GetCurY(s32);
void PadUtils_SetRelXY(s32, s32, s32);

void PadUtils_UpdateRelXY(s32 arg0) {
    s32 sp1C;
    s32 temp_v0;
    s32 var_a1;
    s32 var_a2;

    sp1C = PadUtils_GetCurX(arg0);
    temp_v0 = PadUtils_GetCurY(arg0);
    if (sp1C >= 8) {
        if (sp1C < 0x43) {
            var_a1 = sp1C - 7;
        } else {
            var_a1 = 0x3C;
        }
    } else {
        var_a1 = 0;
        if (sp1C < -7) {
            if (sp1C >= -0x42) {
                var_a1 = sp1C + 7;
            } else {
                var_a1 = -0x3C;
            }
        }
    }
    if (temp_v0 >= 8) {
        if (temp_v0 < 0x43) {
            var_a2 = temp_v0 - 7;
        } else {
            var_a2 = 0x3C;
        }
    } else {
        var_a2 = 0;
        if (temp_v0 < -7) {
            if (temp_v0 >= -0x42) {
                var_a2 = temp_v0 + 7;
            } else {
                var_a2 = -0x3C;
            }
        }
    }
    PadUtils_SetRelXY(arg0, var_a1, var_a2);
}
