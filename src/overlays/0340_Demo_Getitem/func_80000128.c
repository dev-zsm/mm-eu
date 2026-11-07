// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_getitem.h"

void DemoGetitem_PerformCutsceneActions(DemoGetitem* this, PlayState* play) {
    s32 pad;
    u16 bobPhase = (play->gameplayFrames * 1000) % 0x10000;

    if (Cutscene_IsCueInChannel(play, this->cueType)) {
        if (play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id != 4) {
            this->actor.shape.yOffset = 0.0f;
        }

        switch (play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id) {
            case 2:
                this->actor.draw = DemoGetitem_Draw;
                Cutscene_ActorTranslate(&this->actor, play, Cutscene_GetCueChannel(play, this->cueType));
                this->actor.shape.rot.y += 0x3E8;
                break;

            case 3:
                Actor_Kill(&this->actor);
                break;

            case 4:
                this->actor.draw = DemoGetitem_Draw;
                Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, this->cueType));
                this->actor.shape.yOffset = Math_SinS(bobPhase) * 15.0f;
                break;

            default:
                this->actor.draw = NULL;
                break;
        }
    } else {
        this->actor.draw = NULL;
    }
}
