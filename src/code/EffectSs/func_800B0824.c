// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite.h"

s32 EffectSs_FindSlot(s32 priority, s32* index) {
    s32 foundFree;
    s32 i;

    if (sEffectSsInfo.searchStartIndex >= sEffectSsInfo.tableSize) {
        sEffectSsInfo.searchStartIndex = 0;
    }

    
    i = sEffectSsInfo.searchStartIndex;
    foundFree = false;
    while (true) {
        if (sEffectSsInfo.table[i].life == -1) {
            foundFree = true;
            break;
        }

        i++;

        if (i >= sEffectSsInfo.tableSize) {
            i = 0; 
        }

        
        if (i == sEffectSsInfo.searchStartIndex) {
            break;
        }
    }

    if (foundFree == true) {
        *index = i;
        return 0;
    }

    
    
    i = sEffectSsInfo.searchStartIndex;
    while (true) {
        
        if ((priority <= sEffectSsInfo.table[i].priority) &&
            !((priority == sEffectSsInfo.table[i].priority) && (sEffectSsInfo.table[i].flags & 1))) {
            break;
        }

        i++;

        if (i >= sEffectSsInfo.tableSize) {
            i = 0; 
        }

        
        if (i == sEffectSsInfo.searchStartIndex) {
            return 1;
        }
    }

    *index = i;
    return 0;
}
