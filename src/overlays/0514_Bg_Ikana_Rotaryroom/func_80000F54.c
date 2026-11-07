// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B81234(BgIkanaRotaryroom* this, PlayState* play) {
    s32 pad[2];
    Player* player = GET_PLAYER(play);
    BgIkanaRotaryroomStruct3* ptr;
    s32 sp64;
    Vec3f sp58;
    Vec3f sp4C;
    f32 temp_f0;
    f32 sp44 = ref_D_80B82200[player->transformation] * 0.5f;
    CollisionPoly* sp40;
    s32 bgId;

    if (CutsceneManager_GetCurrentCsId() == this->dyna.actor.csId) {
        if (player == NULL) {
            return;
        }

        ptr = &this->unk_520;

        if (player->actor.freezeTimer > 0) {
            sp58.x = ptr->unk_4C.x;
            sp58.y = ptr->unk_4C.y + 50.0f;
            sp58.z = ptr->unk_4C.z;

            sp64 = Math_ScaledStepToS(&player->actor.shape.rot.x, ptr->unk_40.x, 0x7D0) & 1;
            sp64 &= Math_ScaledStepToS(&player->actor.shape.rot.y, ptr->unk_40.y, 0x7D0);
            sp64 &= Math_ScaledStepToS(&player->actor.shape.rot.z, ptr->unk_40.z, 0x7D0);

            ptr->unk_48 -= 2.1f;
            ptr->unk_48 *= 0.98f;
            if (ptr->unk_48 < -30.0f) {
                ptr->unk_48 = -30.0f;
            }
            ptr->unk_4C.y += ptr->unk_48;

            Matrix_Push();

            Matrix_RotateYS(player->actor.shape.rot.y, MTXMODE_NEW);
            Matrix_RotateXS(player->actor.shape.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(player->actor.shape.rot.z, MTXMODE_APPLY);
            Matrix_MultVecY(sp44, &sp4C);

            Matrix_Pop();

            temp_f0 = BgCheck_EntityRaycastFloor5_2(play, &play->colCtx, &sp40, &bgId, NULL, &sp58);
            if (ptr->unk_4C.y <= temp_f0) {
                ptr->unk_4C.y = temp_f0;
            } else {
                sp64 = 0;
            }

            Math_Vec3f_Copy(&player->actor.home.pos, &player->actor.world.pos);

            player->actor.world.pos.x = ptr->unk_4C.x - sp4C.x;
            player->actor.world.pos.y = (ptr->unk_4C.y - sp4C.y) + sp44;
            player->actor.world.pos.z = ptr->unk_4C.z - sp4C.z;

            if (sp64 != 0) {
                Math_Vec3f_Copy(&player->actor.home.pos, &player->actor.world.pos);
                this->unk_57C = NULL;
            } else {
                player->actor.freezeTimer = 2;
            }
        }
    } else {
        if (player != NULL) {
            player->actor.shape.rot = this->unk_520.unk_40;
            Math_Vec3f_Copy(&player->actor.home.pos, &player->actor.world.pos);
        }
        this->unk_57C = NULL;
    }
}
