// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_getitem.h"

void DemoGetitem_Wait(DemoGetitem* this, PlayState* play) {
    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        this->actor.draw = NULL;
        this->actor.objectSlot = this->objectSlot;
        this->actionFunc = DemoGetitem_PerformCutsceneActions;
    }
}
