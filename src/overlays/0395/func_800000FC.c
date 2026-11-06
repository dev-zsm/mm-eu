// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_elvpole.h"

void ref_func_80ABD92C(BgHakuginElvpole* this, PlayState* play) {
    Actor* thisx = &this->dyna.actor;
    s32 sp28 = false;
    f32 var_fv1;

    if (this->unk_15E > 0) {
        if ((thisx->world.pos.y - thisx->home.pos.y) < -120.0f) {
            thisx->world.pos.y += 4.0f;
            sp28 = true;
        } else if (this->unk_15E > 0) {
            if (this->unk_15E == 100) {
                Actor_PlaySfx(thisx, NA_SE_EV_STONEDOOR_STOP);
            }
            thisx->world.pos.y = thisx->home.pos.y - 120.0f;

            this->unk_15E--;
        }
    } else if (this->unk_15E == 0) {
        if ((thisx->world.pos.y - thisx->home.pos.y) > -320.0f) {
            thisx->world.pos.y -= 4.0f;
            sp28 = true;
        } else {
            thisx->world.pos.y = thisx->home.pos.y - 320.0f;
            Flags_UnsetSwitch(play, BGHAKUGINELVPOLE_GET_SWITCH_FLAG(thisx));
            this->unk_15E = -1;
            Actor_PlaySfx(thisx, NA_SE_EV_STONEDOOR_STOP);
        }
    } else if ((BGHAKUGINELVPOLE_GET_SWITCH_FLAG(thisx) != 0x7F) &&
               Flags_GetSwitch(play, BGHAKUGINELVPOLE_GET_SWITCH_FLAG(thisx))) {
        this->unk_15E = 0x64;
        this->unk_160 = true;
    }

    if (sp28 || (this->unk_15C & 7)) {
        if (this->unk_15C & 1) {
            var_fv1 = 1.0f;
        } else {
            var_fv1 = -1.0f;
        }
        this->unk_15C++;
        thisx->world.pos.x = (Math_SinS(this->unk_15C * 0x2000) * var_fv1) + thisx->home.pos.x;
        thisx->world.pos.z = (Math_CosS(this->unk_15C * 0x2000) * var_fv1) + thisx->home.pos.z;
        Actor_PlaySfx_Flagged(thisx, NA_SE_EV_PLATE_LIFT_LEVEL - SFX_FLAG);
    } else {
        this->unk_15C = 0;
    }

    if (this->unk_160) {
        if (thisx->csId == CS_ID_NONE) {
            this->unk_160 = false;
            return;
        } else if (CutsceneManager_IsNext(thisx->csId)) {
            CutsceneManager_StartWithPlayerCs(thisx->csId, thisx);
            this->unk_160 = false;
            return;
        }
        CutsceneManager_Queue(thisx->csId);
    }
}
