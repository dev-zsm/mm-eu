// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_hahen.h"

void EffectSsHahen_Update(PlayState* play, u32 index, EffectSs* this) {
    Player* player = GET_PLAYER(play);

    this->rPitch += 0x37;
    this->rYaw += 0xA;

    if ((this->pos.y <= player->actor.floorHeight) && (this->life < this->rMinLife)) {
        this->life = 0;
    }

    if (this->rObjectId != HAHEN_OBJECT_DEFAULT) {
        EffectSsHahen_CheckForObject(this, play);
    }
}
