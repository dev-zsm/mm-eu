// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnArrow_Update), score 7.00 (7 differ, size +1)
#include "generated/mm/z_en_arrow.h"

void func_800014E0(Actor* thisx, PlayState* play) {
    static Vec3f sVelocity = { 0.0f, 0.5f, 0.0f };
    static Vec3f sAccel = { 0.0f, 0.5f, 0.0f };
    static Color_RGBA8 sPrimColor = { 255, 255, 100, 255 };
    static Color_RGBA8 sEnvColor = { 255, 50, 0, 0 };
    s32 pad;
    EnArrow* this = (EnArrow*)thisx;
    Player* player = GET_PLAYER(play);

    if ((this->unk_263 != 0) ||
        ((this->actor.params >= ARROW_TYPE_NORMAL_LIT) &&
         ((this->actor.params == ARROW_TYPE_DEKU_BUBBLE) || (player->unk_D57 != 0))) ||
        !Player_InBlockingCsMode(play, player)) {
        this->actionFunc(this, play);
    }

    if (ARROW_IS_MAGICAL(this->actor.params)) {
        s16 sp44[] = {
            ACTOR_ARROW_FIRE,  
            ACTOR_ARROW_ICE,   
            ACTOR_ARROW_LIGHT, 
        };

        if (this->actor.child == NULL) {
            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, sp44[ARROW_GET_MAGIC_FROM_TYPE(this->actor.params)],
                               this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, 0);
        }
    } else if (this->actor.params == ARROW_TYPE_NORMAL_LIT) {
        ref_func_800B0EB0(play, &this->unk_234, &sVelocity, &sAccel, &sPrimColor, &sEnvColor, 100, 0, 8);
    }

    Math_Vec3f_Copy(&this->actor.home.pos, &this->actor.prevPos);
}
