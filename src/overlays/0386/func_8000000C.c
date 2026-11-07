// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char07.h"

void DmChar07_Init(Actor* thisx, PlayState* play) {
    DmChar07* this = (DmChar07*)thisx;

    this->isStage = 0;
    Actor_SetScale(&this->dyna.actor, 1.0f);
    this->spotlightFlags = DMCHAR07_GET_SPOTLIGHTFLAGS(thisx);
    thisx->params = DMCHAR07_GET_TYPE(thisx);
    if (this->dyna.actor.params == DMCHAR07_STAGE) {
        Actor_SetScale(&this->dyna.actor, 0.1f);
        this->isStage = 1;
        DynaPolyActor_Init(&this->dyna, 0);
        DynaPolyActor_LoadMesh(play, &this->dyna, &object_milkbar_Colheader_006688);
    } else {
        Actor_SetScale(&this->dyna.actor, 1.0f);
    }
    DmChar07_SetupAction(this, DmChar07_DoNothing);
}
