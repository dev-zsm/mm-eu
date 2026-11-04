// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_DLF.h"

void Overlay_LoadGameState(GameStateOverlay* overlayEntry) {
    void* vramStart;

    if (overlayEntry->loadedRamAddr != NULL) {
        PRINTF(T("OVL(d):既にリンクされています\n", "OVL(d): Already linked\n"));
        return;
    }

    vramStart = overlayEntry->vramStart;
    if (vramStart == NULL) {
        overlayEntry->unk_28 = 0;
        return;
    }

    overlayEntry->loadedRamAddr = Overlay_AllocateAndLoad(overlayEntry->file.vromStart, overlayEntry->file.vromEnd,
                                                          vramStart, overlayEntry->vramEnd);

    if (overlayEntry->loadedRamAddr == NULL) {
        PRINTF(T("OVL(d):ロードに失敗しました\n", "OVL(d): Loading failed\n"));
        return;
    }

    PRINTF("OVL(d):Seg:%08x-%08x Ram:%08x-%08x Off:%08x %s\n", overlayEntry->vramStart, overlayEntry->vramEnd,
           overlayEntry->loadedRamAddr,
           (uintptr_t)overlayEntry->loadedRamAddr + (uintptr_t)overlayEntry->vramEnd -
               (uintptr_t)overlayEntry->vramStart,
           (uintptr_t)overlayEntry->vramStart - (uintptr_t)overlayEntry->loadedRamAddr, "");

#if MM_VERSION >= N64_US
    overlayEntry->unk_14 =
        (void*)(uintptr_t)((overlayEntry->unk_14 != NULL) ? (void*)((uintptr_t)overlayEntry->unk_14 -
                                                                    (intptr_t)((uintptr_t)overlayEntry->vramStart -
                                                                               (uintptr_t)overlayEntry->loadedRamAddr))
                                                          : NULL);

    overlayEntry->init =
        (void*)(uintptr_t)((overlayEntry->init != NULL) ? (void*)((uintptr_t)overlayEntry->init -
                                                                  (intptr_t)((uintptr_t)overlayEntry->vramStart -
                                                                             (uintptr_t)overlayEntry->loadedRamAddr))
                                                        : NULL);

    overlayEntry->destroy =
        (void*)(uintptr_t)((overlayEntry->destroy != NULL) ? (void*)((uintptr_t)overlayEntry->destroy -
                                                                     (intptr_t)((uintptr_t)overlayEntry->vramStart -
                                                                                (uintptr_t)overlayEntry->loadedRamAddr))
                                                           : NULL);

    overlayEntry->unk_20 =
        (void*)(uintptr_t)((overlayEntry->unk_20 != NULL) ? (void*)((uintptr_t)overlayEntry->unk_20 -
                                                                    (intptr_t)((uintptr_t)overlayEntry->vramStart -
                                                                               (uintptr_t)overlayEntry->loadedRamAddr))
                                                          : NULL);

    overlayEntry->unk_24 =
        (void*)(uintptr_t)((overlayEntry->unk_24 != NULL) ? (void*)((uintptr_t)overlayEntry->unk_24 -
                                                                    (intptr_t)((uintptr_t)overlayEntry->vramStart -
                                                                               (uintptr_t)overlayEntry->loadedRamAddr))
                                                          : NULL);
#else
    if (overlayEntry->unk_14 != NULL) {
        overlayEntry->unk_14 =
            (void*)((uintptr_t)overlayEntry->unk_14 -
                    (intptr_t)((uintptr_t)overlayEntry->vramStart - (uintptr_t)overlayEntry->loadedRamAddr));
    } else {
        overlayEntry->unk_14 = NULL;
    }

    if (overlayEntry->init != NULL) {
        overlayEntry->init =
            (void*)((uintptr_t)overlayEntry->init -
                    (intptr_t)((uintptr_t)overlayEntry->vramStart - (uintptr_t)overlayEntry->loadedRamAddr));
    } else {
        overlayEntry->init = NULL;
    }

    if (overlayEntry->destroy != NULL) {
        overlayEntry->destroy =
            (void*)((uintptr_t)overlayEntry->destroy -
                    (intptr_t)((uintptr_t)overlayEntry->vramStart - (uintptr_t)overlayEntry->loadedRamAddr));
    } else {
        overlayEntry->destroy = NULL;
    }

    if (overlayEntry->unk_20 != NULL) {
        overlayEntry->unk_20 =
            (void*)((uintptr_t)overlayEntry->unk_20 -
                    (intptr_t)((uintptr_t)overlayEntry->vramStart - (uintptr_t)overlayEntry->loadedRamAddr));
    } else {
        overlayEntry->unk_20 = NULL;
    }

    if (overlayEntry->unk_24 != NULL) {
        overlayEntry->unk_24 =
            (void*)((uintptr_t)overlayEntry->unk_24 -
                    (intptr_t)((uintptr_t)overlayEntry->vramStart - (uintptr_t)overlayEntry->loadedRamAddr));
    } else {
        overlayEntry->unk_24 = NULL;
    }
#endif

    overlayEntry->unk_28 = 0;
}
