// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_moonend.h"

void DemoMoonend_Init(Actor* thisx, PlayState* play) {
    DemoMoonend* this = (DemoMoonend*)thisx;

    Actor_SetScale(&this->actor, 0.1f);
    this->actionFunc = DemoMoonend_DoNothing;

    if (DEMOMOONEND_GET_PARAM_F(thisx) == 1) {
        Actor_SetScale(&this->actor, 0.05f);
        Actor_SetScale(&this->actor, 6.0f);
        this->actor.draw = NULL;
        this->cueType = CS_CMD_ACTOR_CUE_558;
        this->actionFunc = ref_func_80C17B60;
    } else {
        Actor_SetScale(&this->actor, 0.095f);
        Keyframe_InitFlex(&this->kfSkelAnime, &object_moonend_KFSkel_00B5A0, &object_moonened_KFAnim_001214,
                          this->jointTable, this->morphTable, NULL);
        Keyframe_FlexPlayOnce(&this->kfSkelAnime, &object_moonened_KFAnim_001214);
        this->cueType = CS_CMD_ACTOR_CUE_560;
        this->actionFunc = ref_func_80C17C48;
        this->actor.home.rot.z = 0;
        this->actor.draw = NULL;
        this->kfSkelAnime.frameCtrl.speed = 2.0f / 3.0f;
    }
}
