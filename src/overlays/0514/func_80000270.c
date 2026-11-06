// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B80550(BgIkanaRotaryroom* this, PlayState* play) {
    s32 pad;
    s32 spC8 = BGIKANAROTARYROOM_GET_1(&this->dyna.actor);
    s32 spC4;
    s32 pad2;
    Vec3f spB4;
    Actor* actor;
    s32 i;
    BgIkanaRotaryroomStruct4* ptr;
    MtxF sp68;
    Vec3s sp60;

    if (Flags_GetSwitch(play, BGIKANAROTARYROOM_GET_SWITCH_FLAG_1(&this->dyna.actor))) {
        spC4 = 1;
    } else {
        spC4 = 0;
    }

    actor = play->actorCtx.actorLists[ACTORCAT_DOOR].first;
    Matrix_Push();
    sp60.x = BINANG_ROT180(this->dyna.actor.home.rot.x);
    sp60.y = this->dyna.actor.home.rot.y;
    sp60.z = this->dyna.actor.home.rot.z;
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &sp60);

    while (actor != NULL) {
        if (actor->id == ACTOR_DOOR_SHUTTER) {
            Math_Vec3f_Diff(&actor->world.pos, &this->dyna.actor.world.pos, &spB4);

            for (i = 0; i < ARRAY_COUNT(ref_D_80B82184); i++) {
                ptr = &ref_D_80B82184[spC8][i];

                if ((Math3D_Vec3fDistSq(&spB4, &ref_D_80B82184[spC8][i].unk_04) < SQ(250.0f)) &&
                    ((ptr->unk_00 ^ spC4) && (ptr->unk_01 == 0))) {
                    Matrix_Push();
                    Matrix_Translate(spB4.x, spB4.y, spB4.z, MTXMODE_APPLY);
                    Matrix_RotateYS(actor->shape.rot.y - this->dyna.actor.home.rot.y, MTXMODE_APPLY);
                    Matrix_RotateXS(actor->shape.rot.x - this->dyna.actor.home.rot.x, MTXMODE_APPLY);
                    Matrix_RotateZS(actor->shape.rot.z - this->dyna.actor.home.rot.z, MTXMODE_APPLY);
                    Matrix_MultZero(&actor->world.pos);
                    ref_func_80B80358(&actor->world.pos);
                    Matrix_Get(&sp68);
                    Matrix_MtxFToYXZRot(&sp68, &actor->shape.rot, false);
                    Matrix_Pop();
                }
            }
        }
        actor = actor->next;
    }

    Matrix_Pop();
}
