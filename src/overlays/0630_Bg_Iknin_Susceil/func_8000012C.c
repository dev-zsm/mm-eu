// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknin_susceil.h"

void BgIkninSusceil_RequestQuakeAndRumble(BgIkninSusceil* this, PlayState* play, s16 quakeY, s16 quakeDuration,
                                          s32 rumbleType) {
    s32 pad;
    s16 quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_3);

    Quake_SetSpeed(quakeIndex, 31536);
    Quake_SetPerturbations(quakeIndex, quakeY, 0, 0, 0);
    Quake_SetDuration(quakeIndex, quakeDuration);

    if (rumbleType == 1) {
        Rumble_Request(SQ(100.0f), 255, 20, 150);
    } else if (rumbleType == 2) {
        Rumble_Request(SQ(100.0f), 180, 20, 100);
    } else if (rumbleType == 3) {
        Rumble_Request(SQ(100.0f), 120, 20, 10);
    }
}
