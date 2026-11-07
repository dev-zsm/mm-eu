// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall2.h"

void EnFall2_Init(Actor* thisx, PlayState* play) {
    EnFall2* this = (EnFall2*)thisx;

    Actor_SetScale(&this->actor, 1.0f);
    this->actionFunc = EnFall2_DoNothing;
    Keyframe_InitFlex(&this->kfSkelAnime, &object_fall2_KFSkel_008898, &object_fall2_KFAnim_005EF4, this->jointTable,
                      this->morphTable, NULL);
    Keyframe_FlexPlayLoop(&this->kfSkelAnime, &object_fall2_KFAnim_005EF4);
    this->unk2DC = Lib_SegmentedToVirtual(object_fall2_Matanimheader_008840);
    Actor_SetScale(&this->actor, 0.02f);
    this->actionFunc = EnFall2_HandleCutscene;
    this->cueType = CS_CMD_ACTOR_CUE_561;
    this->alphaLevel = 0.0f;
}
