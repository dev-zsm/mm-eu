// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ObjHugebombiwa_RequestQuakeAndRumble(ObjHugebombiwa* this, PlayState* play, s32 quakeVerticalMag) {
    s32 pad[2];
    s16 quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_3);

    Quake_SetSpeed(quakeIndex, 20000);
    Quake_SetPerturbations(quakeIndex, quakeVerticalMag, 0, 0, 0);
    Quake_SetDuration(quakeIndex, 7);

    Rumble_Request(this->actor.xyzDistToPlayerSq, 255, 20, 150);
}
