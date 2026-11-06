// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

BgIkanaRotaryroomStruct4* ref_func_80B80778(BgIkanaRotaryroom* this, PlayState* play, Actor* arg2) {
    s32 i;
    Vec3f sp68;
    s32 pad[2];
    s32 temp_s3 = BGIKANAROTARYROOM_GET_1(&this->dyna.actor);
    BgIkanaRotaryroomStruct4* sp58 = NULL;
    BgIkanaRotaryroomStruct4* ptr;

    if (1) {}

    if (arg2->id == ACTOR_DOOR_SHUTTER) {
        Matrix_Push();

        for (i = 0; i < ARRAY_COUNT(ref_D_80B82184); i++) {
            ptr = &ref_D_80B82184[temp_s3][i];
            if ((ptr->unk_01 == 0) &&
                (Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                              this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot),
                 Matrix_MultVec3f(&ptr->unk_04, &sp68), (Math3D_Vec3fDistSq(&arg2->world.pos, &sp68) < SQ(250.0f)))) {
                sp58 = ptr;
                break;
            }
        }

        Matrix_Pop();
    }
    return sp58;
}
