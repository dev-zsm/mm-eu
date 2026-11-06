// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_col_man.h"

void ref_func_80AFE25C(EnColMan* this, PlayState* play) {
    this->scale = BREG(55) * 0.01f + 0.05f;

    if (BREG(60) || (this->actor.world.rot.z != 0)) {
        if (this->actor.params == EN_COL_MAN_CUTSCENE_BOMB) {
            Actor_Spawn(&play->actorCtx, play, ACTOR_EN_CLEAR_TAG, this->actor.parent->world.pos.x,
                        this->actor.parent->world.pos.y, this->actor.parent->world.pos.z, 0, 0, 0,
                        CLEAR_TAG_PARAMS(CLEAR_TAG_SMALL_EXPLOSION));
        } else {
            EnBom* bomb = (EnBom*)Actor_Spawn(&play->actorCtx, play, ACTOR_EN_BOM, this->actor.world.pos.x,
                                              this->actor.world.pos.y, this->actor.world.pos.z,
                                              BOMB_EXPLOSIVE_TYPE_BOMB, 0, 0, BOMB_TYPE_BODY);

            if (bomb != NULL) {
                bomb->timer = 0;
            }
        }

        Actor_PlaySfx(&this->actor, NA_SE_IT_BOMB_EXPLOSION);
        Actor_Kill(&this->actor);
    }
}
