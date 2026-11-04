// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite.h"

void EffectSs_Spawn(PlayState* play, s32 type, s32 priority, void* initData) {
    s32 index;
    u32 overlaySize;
    EffectSsOverlay* overlayEntry = &gEffectSsOverlayTable[type];
    EffectSsProfile* profile;

    if (EffectSs_FindSlot(priority, &index) != 0) {
        
        return;
    }

    sEffectSsInfo.searchStartIndex = index + 1;
    overlaySize = (uintptr_t)overlayEntry->vramEnd - (uintptr_t)overlayEntry->vramStart;

    if (overlayEntry->vramStart == NULL) {
        PRINTF(T("EffectSoftSprite2_makeEffect():オーバーレイではありません。\n",
                 "EffectSoftSprite2_makeEffect(): Not an overlay.\n"));
        profile = overlayEntry->profile;
    } else {
        if (overlayEntry->loadedRamAddr == NULL) {
            overlayEntry->loadedRamAddr = ZeldaArena_MallocR(overlaySize);

            if (overlayEntry->loadedRamAddr == NULL) {
                return;
            }

            Overlay_Load(overlayEntry->file.vromStart, overlayEntry->file.vromEnd, overlayEntry->vramStart,
                         overlayEntry->vramEnd, overlayEntry->loadedRamAddr);
        }

        profile = (void*)(uintptr_t)((overlayEntry->profile != NULL)
                                         ? (void*)((uintptr_t)overlayEntry->profile -
                                                   (intptr_t)((uintptr_t)overlayEntry->vramStart -
                                                              (uintptr_t)overlayEntry->loadedRamAddr))
                                         : NULL);
    }

    if (profile->init == NULL) {
        return;
    }

    
    EffectSs_Delete(&sEffectSsInfo.table[index]);

    sEffectSsInfo.table[index].type = type;
    sEffectSsInfo.table[index].priority = priority;

    if (profile->init(play, index, &sEffectSsInfo.table[index], initData) == 0) {
        EffectSs_Reset(&sEffectSsInfo.table[index]);
    }
}
