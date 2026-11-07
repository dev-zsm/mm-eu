// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_kankyo.h"

void DemoKakyo_GiantObjectCheck(DemoKankyo* this, PlayState* play) {
    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        this->isSafeToDrawGiants = true;
        this->actor.objectSlot = this->objectSlot;
        DemoKankyo_SetupAction(this, DemoKakyo_MoonSparklesActionFunc);
    }
}
