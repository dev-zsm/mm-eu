// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightblock.h"

void ObjLightblock_FadeAway(ObjLightblock* this, PlayState* play) {
    this->timer--;
    if (this->timer <= 0) {
        CutsceneManager_Stop(this->dyna.actor.csId);
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if (this->timer <= 60) {
        if (this->alpha > 40) {
            this->alpha -= 40;
        } else {
            this->alpha = 0;
            this->dyna.actor.draw = NULL;
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        }
    }
}
