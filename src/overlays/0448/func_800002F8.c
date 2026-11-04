// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_gakufu.h"

void EnGakufu_GiveReward(EnGakufu* this, PlayState* play) {
    s32 hour;
    s32 i;

    Audio_PlaySfx(NA_SE_SY_CORRECT_CHIME);

    hour = TIME_TO_HOURS_F(CURRENT_TIME);
    for (i = 0; i < 3; i++) {
        Item_DropCollectible(play, &sRewardDropsSpawnTerminaFieldPos, sRewardDrops[i + sRewardDropsIndex[hour]]);
    }

    this->actionFunc = EnGakufu_DoNothing;
}
