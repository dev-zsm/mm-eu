// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_market_step.h"

void BgMarketStep_Draw(Actor* thisx, PlayState* play) {
    s32 timeOfDay = BG_MARKET_STEP_GET_TIME_OF_DAY(thisx);

    Gfx_DrawDListOpa(play, sMarketDLs[timeOfDay]);
    Gfx_DrawDListOpa(play, sBankAdvertisementsAndDoorDLs[timeOfDay]);
}
