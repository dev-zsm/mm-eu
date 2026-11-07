// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_open_shutter.h"

s8 ref_func_80ACABA8(BgOpenShutter* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 temp_fv0;
    s16 temp_v0;

    if (!Player_InCsMode(play) && (this->slidingDoor.dyna.actor.xzDistToPlayer < 100.0f)) {
        temp_fv0 = ref_func_80ACAB10(play, &this->slidingDoor.dyna.actor, 0.0f, 65.0f, 15.0f);
        if (fabsf(temp_fv0) < 50.0f) {
            temp_v0 = player->actor.shape.rot.y - this->slidingDoor.dyna.actor.shape.rot.y;
            if (temp_fv0 > 0.0f) {
                temp_v0 = (0x8000 - temp_v0);
            }
            if (ABS_ALT(temp_v0) < 0x3000) {
                if (temp_fv0 > 1.0f) {
                    return 1;
                }
                if (temp_fv0 < -1.0f) {
                    return -1;
                }
            }
        }
    }
    return 0;
}
