// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C16BD4(DemoSyoten* this, PlayState* play) {
    s32 pad;
    u16 cueId;

    if (Cutscene_IsCueInChannel(play, this->cueType)) {
        cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id;
        if (this->cueId != cueId) {
            this->cueId = cueId;
            switch (cueId) {
                case 1:
                case 2:
                    this->actor.draw = NULL;
                    Actor_SetScale(&this->actor, 0.0f);
                    break;

                case 3:
                    this->actor.draw = DemoSyoten_Draw;
                    this->unk_3E4 &= ~4;
                    this->unk_3E4 |= 1;
                    this->actor.shape.rot.z = 0;
                    break;

                case 4:
                    this->actor.draw = DemoSyoten_Draw;
                    ref_func_80C16760(this, play);
                    this->unk_3E4 |= 4;
                    this->unk_3E4 &= ~1;
                    break;

                default:
                    this->actor.draw = NULL;
                    break;
            }
        }

        switch (cueId) {
            case 3:
                if (this->actor.scale.x < 0.05f) {
                    this->actor.scale.x += 0.000625f;
                }
                Actor_SetScale(&this->actor, this->actor.scale.x);
                break;

            case 4:
                this->actor.speed =
                    play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->rot.z * 0.005493164f;
                if (this->unk_3EC < this->path->count) {
                    if (ref_func_80C16818(this)) {
                        this->unk_3EC++;
                    }
                    ref_func_80C168D0(this, play);
                }
                break;
        }
    } else {
        this->actor.draw = NULL;
    }
}
