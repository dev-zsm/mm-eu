// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 pad0[3];
    u32 bssSize;
    s32 nRelocations;
} OvlHeader;

void DmaMgr_RequestSync(void *dst, u32 vrom, u32 size);
void bzero(void *p, u32 n);
void func_80084A00(void *base, void *hdr, void *vram);
void func_8008A780(void *p, u32 n);
void osInvalICache(void *p, u32 n);

u32 func_80084C6C(u32 vromStart, u32 vromEnd, void *vramStart, void *ram, u32 maxSize) {
    u32 size;
    u8 *end;
    OvlHeader *hdr;
    u32 total;

    size = vromEnd - vromStart;
    DmaMgr_RequestSync(ram, vromStart, size);
    end = (u8 *)ram + size;
    hdr = (OvlHeader *)(end - ((s32 *)end)[-1]);
    total = hdr->bssSize + size;
    if (maxSize < total) {
        return 0;
    }
    maxSize = total;
    func_80084A00(ram, hdr, vramStart);
    if (hdr->bssSize != 0) {
        bzero(end, hdr->bssSize);
    }
    bzero(hdr, hdr->nRelocations * 4 + 0x14);
    func_8008A780(ram, maxSize);
    osInvalICache(ram, maxSize);
    return maxSize;
}
