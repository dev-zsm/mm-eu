// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 textSize;
    u32 dataSize;
    u32 rodataSize;
    u32 bssSize;
    u32 nRelocations;
    u32 relocations[1];
} OverlayRelocationSection;

s32 DmaMgr_RequestSync(void *a0, u32 a1, u32 a2);
void func_80084E40(void *a0, void *a1, u32 a2);
void bzero(void *a0, u32 a1);
void func_8008A780(void *a0, u32 a1);
void osInvalICache(void *a0, u32 a1);

u32 func_80085074(u32 vromStart, u32 vromEnd, u32 vramStart, u32 vramEnd, void *allocatedRamAddr) {
    u32 size = vromEnd - vromStart;
    void *end;
    OverlayRelocationSection *ovl;

    DmaMgr_RequestSync(allocatedRamAddr, vromStart, size);
    end = (void *)((u32)allocatedRamAddr + size);
    ovl = (OverlayRelocationSection *)((u32)end - ((u32 *)end)[-1]);
    func_80084E40(allocatedRamAddr, ovl, vramStart);
    if (ovl->bssSize != 0) {
        bzero(end, ovl->bssSize);
    }
    bzero(ovl, (u32)&ovl->relocations[ovl->nRelocations] - (u32)ovl);
    size = vramEnd - vramStart;
    func_8008A780(allocatedRamAddr, size);
    osInvalICache(allocatedRamAddr, size);
    return size;
}
