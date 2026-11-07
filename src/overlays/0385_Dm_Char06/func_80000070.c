// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char06.h"

void DmChar06_HandleCutscene(DmChar06* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_463)) {
        s32 cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_463);

        if ((play->csCtx.curFrame >= play->csCtx.actorCues[cueChannel]->startFrame) &&
            (play->csCtx.actorCues[cueChannel]->endFrame >= play->csCtx.curFrame)) {
            if (play->csCtx.actorCues[cueChannel]->id == 1) {
                this->alpha = 255;
            } else if (play->csCtx.actorCues[cueChannel]->id == 2) {
                f32 lerp =
                    1.0f - Environment_LerpWeight(play->csCtx.actorCues[cueChannel]->endFrame,
                                                  play->csCtx.actorCues[cueChannel]->startFrame, play->csCtx.curFrame);
                this->alpha = 255 * lerp;
            }
        }
    }
}
