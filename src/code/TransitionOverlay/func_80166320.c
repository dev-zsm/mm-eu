#include "types.h"

typedef struct {
    u32 vromAddr;
    u32 vramStart;
    u32 vramEnd;
} OverlayEntry;

extern u32 Lib_PhysicalToVirtual(u32 addr);

u32 TransitionOverlay_VramToRam(OverlayEntry *overlay, u32 vramAddr) {
    u32 ramAddr = Lib_PhysicalToVirtual(overlay->vromAddr & 0xFFFFFF);

    if (ramAddr != 0 && vramAddr >= overlay->vramStart && vramAddr < overlay->vramEnd) {
        return ramAddr - overlay->vramStart + vramAddr;
    }
    return vramAddr;
}
