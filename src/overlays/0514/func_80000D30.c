// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B81010(BgIkanaRotaryroom* this, PlayState* play) {
    s32 pad;
    f32 temp_f0;
    s32 temp_s2;
    s32 phi_s7;
    s32 i;
    Actor* ptr;
    Vec3f sp84;
    BgIkanaRotaryroomStruct2* ptr2;
    CollisionPoly* sp7C;
    s32 bgId;

    if (CutsceneManager_GetCurrentCsId() == this->dyna.actor.csId) {
        phi_s7 = true;

        for (i = 0; i < ARRAY_COUNT(this->unk_3E0); i++) {
            ptr = this->unk_3E0[i].unk_00;
            ptr2 = &this->unk_3E0[i];

            if (ptr != NULL) {
                temp_s2 = Math_ScaledStepToS(&ptr->shape.rot.x, ptr2->unk_44.x, 0xBB8) & 1;
                temp_s2 &= Math_ScaledStepToS(&ptr->shape.rot.y, ptr2->unk_44.y, 0xBB8);
                temp_s2 &= Math_ScaledStepToS(&ptr->shape.rot.z, ptr2->unk_44.z, 0xBB8);

                ptr2->unk_4C -= 2.0f;
                if (ptr2->unk_4C < -30.0f) {
                    ptr2->unk_4C = -30.0f;
                }

                Math_Vec3f_Copy(&ptr->prevPos, &ptr->world.pos);

                ptr->world.pos.y += ptr2->unk_4C;

                sp84.x = ptr->prevPos.x;
                sp84.y = ptr->prevPos.y + 50.0f;
                sp84.z = ptr->prevPos.z;

                temp_f0 = BgCheck_EntityRaycastFloor5_2(play, &play->colCtx, &sp7C, &bgId, NULL, &sp84);
                if (ptr->world.pos.y <= temp_f0) {
                    ptr->world.pos.y = temp_f0;
                } else {
                    temp_s2 = false;
                }

                if (temp_s2) {
                    ptr2->unk_00 = NULL;
                } else {
                    phi_s7 = false;
                }
            }
        }

        if (phi_s7) {
            this->unk_578 = NULL;
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(this->unk_3E0); i++) {
            ptr = this->unk_3E0[i].unk_00;
            if (ptr != NULL) {
                ptr->shape.rot = this->unk_3E0[i].unk_44;
                Math_Vec3f_Copy(&ptr->prevPos, &ptr->world.pos);
            }
        }
        this->unk_578 = NULL;
    }
}
