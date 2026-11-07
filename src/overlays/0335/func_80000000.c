// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_change.h"

void EffChange_Init(Actor* thisx, PlayState* play) {
    EffChange* this = (EffChange*)thisx;

    this->actionFunc = ref_func_80A4C5CC;
    this->actor.draw = EffChange_Draw;
    EffChange_SetColors(this, EFFCHANGE_GET_COLORS(thisx));
    Actor_SetScale(&this->actor, 0.075f);
    this->primColors[3] = 0;
    Keyframe_InitFlex(&this->kfSkelAnime, &gameplay_keep_KFSkel_02900C, &gameplay_keep_KFAnim_0281DC, this->jointTable,
                      this->morphTable, NULL);
    Keyframe_FlexPlayOnce(&this->kfSkelAnime, &gameplay_keep_KFAnim_0281DC);
    this->step = 0;
    this->actor.shape.rot.y = 0;
    this->kfSkelAnime.frameCtrl.speed = 2.0f / 3.0f;
    CutsceneManager_Queue(CS_ID_GLOBAL_ELEGY);
}
