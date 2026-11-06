// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C16DD4(DemoSyoten* this, PlayState* play) {
    s32 pad;
    u16 cueId;

    if (Cutscene_IsCueInChannel(play, this->cueType)) {
        cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id;
        if (this->cueId != cueId) {
            this->cueId = cueId;
            switch (cueId) {
                case 1:
                    this->actor.draw = NULL;
                    break;

                case 2:
                    this->actor.draw = DemoSyoten_Draw;
                    this->unk_3E6 = -6;
                    Actor_PlaySfx(&this->actor, NA_SE_IT_DM_FLYING_GOD_DASH);
                    break;
            }
        }

        if ((cueId == 2) && (this->unk_3E6 < 40)) {
            this->unk_3E6++;
        }
    } else {
        this->actor.draw = NULL;
    }
}
