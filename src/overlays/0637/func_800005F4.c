// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C16A74(DemoSyoten* this, PlayState* play) {
    u16 cueId;

    Keyframe_UpdateFlex(&this->kfSkelAnime);
    if (Cutscene_IsCueInChannel(play, this->cueType)) {
        if ((play->csCtx.curFrame >= 160) && (play->csCtx.curFrame < 322)) {
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_IKANA_SOUL_LV - SFX_FLAG);
        } else if (play->csCtx.curFrame == 322) {
            Actor_PlaySfx(&this->actor, NA_SE_EV_IKANA_SOUL_TRANSFORM);
        }

        cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id;
        if (this->cueId != cueId) {
            this->cueId = cueId;
            switch (cueId) {
                case 1:
                    this->actor.draw = NULL;
                    break;

                case 2:
                    this->actor.draw = ref_func_80C173B4;
                    this->unk_3D8 = 1.0f;
                    break;

                case 3:
                    break;

                case 4:
                    this->actor.draw = NULL;
                    break;

                default:
                    break;
            }
        }

        if (cueId == 3) {
            if (this->unk_3D8 > 0.0125f) {
                this->unk_3D8 -= 0.0125f;
                if (this->actor.child != NULL) {
                    this->actor.child->home.rot.z = 0x14;
                }
            } else {
                this->actor.draw = NULL;
                if (this->actor.child != NULL) {
                    this->actor.child->home.rot.z = 0;
                }
            }
        }
    } else {
        this->actor.draw = NULL;
    }
}
