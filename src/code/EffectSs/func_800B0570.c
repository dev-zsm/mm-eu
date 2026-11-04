// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite.h"

void EffectSs_InitInfo(PlayState* play, s32 tableSize) {
    u32 i;
    EffectSs* effectSs;
    EffectSsOverlay* overlay;

    sEffectSsInfo.table = (EffectSs*)THA_AllocTailAlign16(&play->state.tha, tableSize * sizeof(EffectSs));
    sEffectSsInfo.searchStartIndex = 0;
    sEffectSsInfo.tableSize = tableSize;

    for (effectSs = &sEffectSsInfo.table[0]; effectSs < &sEffectSsInfo.table[sEffectSsInfo.tableSize]; effectSs++) {
        EffectSs_Reset(effectSs);
    }

    overlay = &gEffectSsOverlayTable[0];
    for (i = 0; i < EFFECT_SS_TYPE_MAX; i++) {
        overlay->loadedRamAddr = NULL;
        overlay++;
    }
}
