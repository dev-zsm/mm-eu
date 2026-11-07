// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C16EAC(DemoSyoten* this, PlayState* play) {
    s32 pad;
    u16 cueId;

    if (Cutscene_IsCueInChannel(play, this->cueType)) {
        cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id;
        if (this->cueId != cueId) {
            this->cueId = cueId;
            switch (cueId) {
                case 1:
                    this->actor.draw = NULL;
                    this->unk_3D8 = 0.0f;
                    Actor_SetScale(&this->actor, 0.5f);
                    break;

                case 2:
                    this->actor.draw = DemoSyoten_Draw;
                    break;
            }
        }

        if (cueId == 2) {
            if (this->actor.scale.x < 8.0f) {
                this->actor.scale.x += 0.1875f;
            }

            Actor_SetScale(&this->actor, this->actor.scale.x);

            if (this->unk_3D8 < 1.0f) {
                this->unk_3D8 += 0.025f;
            }

            if (this->unk_3D8 > 1.0f) {
                this->unk_3D8 = 1.0f;
            }
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_IKANA_PURIFICATION - SFX_FLAG);
        }
    } else {
        this->actor.draw = NULL;
    }
    ref_func_80C16974(this->unk_3D8);
}
