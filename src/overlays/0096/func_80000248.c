// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void DoorWarp1_Init(Actor* thisx, PlayState* play) {
    DoorWarp1* this = (DoorWarp1*)thisx;

    this->unk_1CC = 0;
    this->unk_202 = 0;
    this->unk_203 = 0;
    this->unk_1A0 = NULL;
    this->unk_1C0 = 0.0f;
    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    ActorShape_Init(&this->dyna.actor.shape, 0.0f, NULL, 0.0f);

    this->unk_1D3 = 0;
    this->unk_1D4 = 0;
    this->unk_203 = 0;
    this->unk_204 = 1.0f;

    switch (DOORWARP1_GET_FF(&this->dyna.actor)) {
        case ENDOORWARP1_FF_0:
        case ENDOORWARP1_FF_1:
        case ENDOORWARP1_FF_2:
        case ENDOORWARP1_FF_3:
        case ENDOORWARP1_FF_4:
        case ENDOORWARP1_FF_5:
            ref_func_808B8568(this, play);
            break;
    }

    switch (DOORWARP1_GET_FF(&this->dyna.actor)) {
        case ENDOORWARP1_FF_0:
            ref_func_808B8924(this, play);
            break;

        case ENDOORWARP1_FF_1:
            ref_func_808B8A7C(this, play);
            break;

        case ENDOORWARP1_FF_2:
        case ENDOORWARP1_FF_3:
        case ENDOORWARP1_FF_4:
        case ENDOORWARP1_FF_5:
            this->unk_1D3 = 1;
            DynaPolyActor_Init(&this->dyna, 0);
            DynaPolyActor_LoadMesh(play, &this->dyna, &gWarpBossWarpPlatformCol);
            ref_func_808B8C48(this, play);
            break;

        case ENDOORWARP1_FF_6:
            ref_func_808B8E78(this, play);
            break;
    }

    if ((play->sceneId == SCENE_MITURIN_BS) || (play->sceneId == SCENE_HAKUGIN_BS) ||
        (play->sceneId == SCENE_INISIE_BS) || (play->sceneId == SCENE_SEA_BS)) {
        Environment_StopTime();
        play->interfaceCtx.restrictions.songOfTime = 1;
        play->interfaceCtx.restrictions.songOfSoaring = 1;
    }
}
