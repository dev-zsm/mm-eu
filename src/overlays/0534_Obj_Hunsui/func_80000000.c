// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

s32 ref_func_80B9C450(PlayState* play, s32 switchFlagBase, s32 arg2) {
    s32 sp2C = 1;

    if (arg2 < ARRAY_COUNT(ref_D_80B9DC70)) {
        s32 switchFlagOffset = ref_D_80B9DC70[arg2].unk_00;
        s32 val3 = ref_D_80B9DC70[arg2].unk_01;

        while (switchFlagOffset--) {
            if ((1 << switchFlagOffset) & val3) {
                if (!Flags_GetSwitch(play, switchFlagBase + switchFlagOffset)) {
                    sp2C = 0;
                    break;
                }
            } else if (Flags_GetSwitch(play, switchFlagBase + switchFlagOffset)) {
                sp2C = 0;
                break;
            }
        }
    } else {
        sp2C = 0;
        switch (arg2) {
            case 14:
                if (!Flags_GetSwitch(play, switchFlagBase)) {
                    sp2C = 1;
                }

                if (Flags_GetSwitch(play, switchFlagBase + 1) && Flags_GetSwitch(play, switchFlagBase + 2) &&
                    Flags_GetSwitch(play, switchFlagBase + 3)) {
                    sp2C += 2;
                }
                break;

            case 15:
                if (!Flags_GetSwitch(play, switchFlagBase) ||
                    (Flags_GetSwitch(play, switchFlagBase + 1) && Flags_GetSwitch(play, switchFlagBase + 2) &&
                     Flags_GetSwitch(play, switchFlagBase + 3))) {
                    sp2C = 1;
                }
                break;

            default:
                break;
        }
    }
    return sp2C;
}
