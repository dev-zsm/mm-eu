// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_dharma.h"

void BgIkanaDharma_WaitForCutsceneToEnd(BgIkanaDharma* this, PlayState* play) {
    if (this->cutsceneFramesRemaining > 0) {
        this->cutsceneFramesRemaining--;

        if (this->cutsceneFramesRemaining == 0) {
            if (sFirstHitBgIkanaDharma == this) {
                sFirstHitBgIkanaDharma = NULL;
            }

            CutsceneManager_Stop(this->dyna.actor.csId);
        }
    }

    if (Math_StepToF(&this->dyna.actor.scale.y, 0.0f, 1.0f / 300.0f)) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    this->dyna.actor.scale.x = this->dyna.actor.scale.y * 3.0f;
    this->dyna.actor.scale.z = this->dyna.actor.scale.y * 3.0f;
    BgIkanaDharma_SpawnEffects(this, play);
}
