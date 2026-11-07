// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_lastday.h"

void EffLastday_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EffLastday* this = (EffLastday*)thisx;

    Actor_SetScale(&this->actor, 0.1f);
    switch (EFFLASTDAY_GET_F(&this->actor)) {
        case EFFLASTDAY_PARAM_1:
            this->dList = object_lastday_DL_000510;
            this->matAnim = Lib_SegmentedToVirtual(object_lastday_Matanimheader_000608);
            this->cueType = CS_CMD_ACTOR_CUE_508;
            this->actionFunc = ref_func_80BEBDF8;
            Actor_SetScale(&this->actor, 1.0f);
            break;

        case EFFLASTDAY_PARAM_2:
            this->dList = object_lastday_DL_000210;
            this->matAnim = Lib_SegmentedToVirtual(object_lastday_Matanimheader_000308);
            this->cueType = CS_CMD_ACTOR_CUE_509;
            this->actionFunc = ref_func_80BEBEB8;
            Actor_SetScale(&this->actor, 0.5f);
            break;

        case EFFLASTDAY_PARAM_3:
            this->dList = object_lastday_DL_000060;
            this->matAnim = Lib_SegmentedToVirtual(object_lastday_Matanimheader_000148);
            this->cueType = CS_CMD_ACTOR_CUE_510;
            this->actionFunc = ref_func_80BEBF78;
            Actor_SetScale(&this->actor, 0.2f);
            this->actor.home.rot.z = 0;
            break;

        default:
            this->dList = object_lastday_DL_000370;
            this->matAnim = Lib_SegmentedToVirtual(object_lastday_Matanimheader_000448);
            this->cueType = CS_CMD_ACTOR_CUE_507;
            this->actionFunc = ref_func_80BEBD0C;
            Actor_SetScale(&this->actor, 1.0f);
            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EFF_LASTDAY, this->actor.world.pos.x,
                               this->actor.world.pos.y, this->actor.world.pos.z, 0, this->actor.world.rot.y, 0,
                               EFFLASTDAY_PARAM_1);
            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EFF_LASTDAY, this->actor.world.pos.x,
                               this->actor.world.pos.y, this->actor.world.pos.z, 0, this->actor.world.rot.y, 0,
                               EFFLASTDAY_PARAM_2);
            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EFF_LASTDAY, this->actor.world.pos.x,
                               this->actor.world.pos.y, this->actor.world.pos.z, 0, this->actor.world.rot.y, 0,
                               EFFLASTDAY_PARAM_3);
            break;
    }
}
