// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_overlay.h"

TransitionOverlayStatus TransitionOverlay_Free(TransitionOverlay* overlayEntry) {
    s32 count;
    void* loadedRamAddr;

    if (overlayEntry->file.vromStart == 0) {
        return TRANSITION_OVERLAY_STATUS_INTERNAL;
    }

    loadedRamAddr = Lib_PhysicalToVirtual(overlayEntry->loadInfo.addr);
    if (loadedRamAddr != NULL) {
        count = overlayEntry->loadInfo.count;
        if (count != 0) {
            count--;
            overlayEntry->loadInfo.count = count;
            if (count == 0) {
                ZeldaArena_Free(loadedRamAddr);
                overlayEntry->loadInfo.addr = Lib_VirtualToPhysical(NULL);
                return TRANSITION_OVERLAY_STATUS_LOAD_FREE;
            }
            return TRANSITION_OVERLAY_STATUS_ADD_REMOVAL;
        }
        return TRANSITION_OVERLAY_STATUS_LOADED_NO_INSTANCES;
    }
    return TRANSITION_OVERLAY_STATUS_FAILED;
}
