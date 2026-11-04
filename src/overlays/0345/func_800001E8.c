// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_keikoku_saku.h"

void BgKeikokuSaku_Update(Actor* thisx, PlayState* play) {
    BgKeikokuSaku* this = (BgKeikokuSaku*)thisx;

    if (this->timer) {
        this->timer--;
    }
    this->dyna.actor.world.pos.x = BREG(5) + this->dyna.actor.home.pos.x;
    this->dyna.actor.world.pos.y = BREG(6) + this->dyna.actor.home.pos.y;
    this->dyna.actor.world.pos.z = BREG(7) + this->dyna.actor.home.pos.z;
    this->dyna.actor.scale.x = (BREG(10) / 1000.0f) + 0.1f;
    this->dyna.actor.scale.y = (BREG(11) / 1000.0f) + 0.1f;
    this->dyna.actor.scale.z = (BREG(12) / 1000.0f) + 0.1f;
    this->actionFunc(this, play);
}
