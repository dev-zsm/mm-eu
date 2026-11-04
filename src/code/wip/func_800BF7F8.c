#include "types.h"

typedef struct {
    u8 pad0[8];
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u8 pad14[0xC];
} MapEntry;

extern MapEntry D_801AFB00[];
extern s32 D_801B5140;

u32 ActorOverlayTable_FaultAddrConv(u32 addr, u8 arg1) {
    s32 i;
    s32 n = D_801B5140;
    MapEntry *e = D_801AFB00;

    for (i = 0; i < n; i++) {
        u32 start = e->unk10;
        u32 delta = e->unk8 - start;
        u32 size = e->unkC - e->unk8;

        if (start != 0 && addr >= start && addr < start + size) {
            return addr + delta;
        }
        e++;
    }
    return 0;
}
