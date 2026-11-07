// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_uzu.h"

void ref_func_80A66278(EnWarpUzu* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        ref_func_80A66384(this, play);
    } else {
        s16 phi_a0 = ABS((s16)(Actor_WorldYawTowardActor(&this->actor, &player->actor) - this->actor.shape.rot.y));
        s16 temp_v0 = player->actor.shape.rot.y - this->actor.shape.rot.y;
        s16 phi_v1 = ABS(temp_v0);

        if ((phi_a0 >= 0x2AAB) && (phi_v1 < 0x238E)) {
            Actor_OfferTalk(&this->actor, play, 70.0f);
        }
    }
}
