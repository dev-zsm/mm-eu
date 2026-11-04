// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_boom.h"

void EnBoom_Update(Actor* thisx, PlayState* play) {
    EnBoom* this = (EnBoom*)thisx;
    Player* player = GET_PLAYER(play);
    Actor* actor;

    if (!(player->stateFlags1 & PLAYER_STATE1_20000000)) {
        this->actionFunc(this, play);

        if (((actor = this->actor.child) != NULL) || ((actor = this->actor.parent) != NULL)) {
            this->actor.focus.pos.x = (this->actor.world.pos.x + actor->world.pos.x) * 0.5f;
            this->actor.focus.pos.y = (this->actor.world.pos.y + actor->world.pos.y) * 0.5f;
            this->actor.focus.pos.z = (this->actor.world.pos.z + actor->world.pos.z) * 0.5f;
        } else {
            Actor_SetFocus(&this->actor, 0.0f);
        }

        if (this->actor.params != ZORA_BOOMERANG_LEFT) {
            this->unk_1CD--;
        } else {
            this->unk_1CD++;
        }
    }
}
