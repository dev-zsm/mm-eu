// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_driftice.h"

void ObjDriftice_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjDriftice* this = (ObjDriftice*)thisx;
    f32* sp2C = ref_D_80A67620[OBJDRIFTICE_GET_3(&this->dyna.actor)];
    Path* path;
    s32 transformFlags;
    s32 sp20;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);

    this->dyna.actor.shape.rot.x = 0;
    this->dyna.actor.world.rot.x = 0;
    this->dyna.actor.shape.rot.z = 0;
    this->dyna.actor.world.rot.z = 0;

    Actor_SetScale(&this->dyna.actor, sp2C[0] * 0.035377357f);
    this->dyna.actor.cullingVolumeScale = sp2C[1];
    this->dyna.actor.cullingVolumeDownward = sp2C[2];
    this->unk_240 = 1.0f / this->dyna.actor.scale.x;
    this->unk_23C = ref_D_80A67644[OBJDRIFTICE_GET_E00(&this->dyna.actor)];

    sp20 = 0;
    if (this->unk_23C < 0.01f) {
        sp20 = 1;
    }

    this->unk_244 = thisx->home.rot.z * (0x8000 / 720.0f);

    transformFlags = 0;
    if (sp20 == 0) {
        transformFlags = DYNA_TRANSFORM_POS;
    }

    if (thisx->home.rot.z != 0) {
        transformFlags |= DYNA_TRANSFORM_ROT_Y | DYNA_TRANSFORM_POS;
    }

    DynaPolyActor_Init(&this->dyna, transformFlags);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_driftice_Colheader_001AA8);

    if (sp20 != 0) {
        ref_func_80A671A8(this);
    } else {
        this->dyna.actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;

        path = &play->setupPathList[OBJDRIFTICE_GET_PATH_INDEX(&this->dyna.actor)];
        this->unk_164 = 0;
        this->unk_160 = path->count - 1;
        this->unk_168 = 1;

        this->pathPoints = Lib_SegmentedToVirtual(path->points);
        ref_func_80A66570(this, this->unk_164);
        ref_func_80A671CC(this);
    }
}
