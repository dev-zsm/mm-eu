// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void DemoSyoten_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    DemoSyoten* this = (DemoSyoten*)thisx;

    Actor_SetScale(&this->actor, 0.3f);

    this->actionFunc = ref_func_80C16A64;
    this->unk_3E4 = 0;
    this->unk_3E6 = 0;
    this->unk_3DC = NULL;
    this->unk_3E0 = NULL;
    this->cueId = 0;
    this->unk_3D8 = 1.0f;

    switch (DEMOSYOTEN_GET_F(&this->actor)) {
        case DEMOSYOTEN_F_0:
            Keyframe_InitFlex(&this->kfSkelAnime, &object_syoten_KFSkel_001328, &object_syoten_KFAnim_00023C,
                              this->jointTable, this->morphTable, NULL);
            Keyframe_FlexPlayLoop(&this->kfSkelAnime, &object_syoten_KFAnim_00023C);
            this->actor.draw = NULL;
            this->actionFunc = ref_func_80C16A74;
            this->actor.child =
                Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EFF_DUST, this->actor.world.pos.x,
                                   this->actor.world.pos.y, this->actor.world.pos.z, 0, this->actor.shape.rot.y, 0, 0);
            this->cueType = CS_CMD_ACTOR_CUE_533;
            Actor_SetScale(&this->actor, 0.05f);
            break;

        case DEMOSYOTEN_F_1:
            Actor_SetScale(&this->actor, 0.1f);
            this->unk_3DC = object_syoten_DL_001370;
            this->unk_3E0 = Lib_SegmentedToVirtual(&object_syoten_Matanimheader_001448);
            this->unk_3E4 |= 1;
            this->actionFunc = ref_func_80C16BD4;
            this->cueType = CS_CMD_ACTOR_CUE_533;
            Actor_SetScale(&this->actor, 0.05f);
            break;

        case DEMOSYOTEN_F_2:
            this->unk_3DC = object_syoten_DL_001730;
            this->unk_3E0 = Lib_SegmentedToVirtual(&object_syoten_Matanimheader_0018B8);
            this->cueType = CS_CMD_ACTOR_CUE_534;
            this->actionFunc = ref_func_80C16DD4;
            this->unk_3E4 |= 2;
            Actor_SetScale(&this->actor, 4.0f);
            break;

        case DEMOSYOTEN_F_3:
            this->unk_3DC = object_syoten_DL_001DD0;
            this->unk_3E0 = Lib_SegmentedToVirtual(&object_syoten_Matanimheader_002B98);
            this->cueType = CS_CMD_ACTOR_CUE_536;
            this->unk_3E4 |= 8;
            this->actionFunc = ref_func_80C16EAC;
            Actor_SetScale(&this->actor, 0.5f);
            break;

        case DEMOSYOTEN_F_4:
            this->unk_3DC = object_syoten_DL_002880;
            this->unk_3E0 = Lib_SegmentedToVirtual(&object_syoten_Matanimheader_002B88);
            this->unk_3E4 |= 2;
            this->actionFunc = ref_func_80C17008;
            this->cueType = CS_CMD_ACTOR_CUE_535;
            this->unk_3E4 |= 1;
            this->unk_3E4 |= 8;
            this->actor.draw = ref_func_80C17690;
            Actor_SetScale(&this->actor, 5.0f);
            break;
    }
}
