// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom_chu.h"

void EnBomChu_WaitForRelease(EnBomChu* this, PlayState* play) {
    Player* player;

    if (this->timer == 0) {
        EnBomChu_Explode(this, play);
    } else if (Actor_HasNoParent(&this->actor, play)) {
        player = GET_PLAYER(play);
        Math_Vec3f_Copy(&this->actor.world.pos, &player->actor.world.pos);
        Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);

        this->actor.shape.rot.y = player->actor.shape.rot.y;
        this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
        Actor_PlaySfx_SurfaceBomb(play, &this->actor);

        this->isMoving = true;
        this->actor.speed = 8.0f;
        this->movingSpeed = 8.0f;
        EnBomChu_SetupMove(this);
    }
}
