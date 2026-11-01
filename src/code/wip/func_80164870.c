#include "types.h"

typedef struct {
    u32 start;
    u8 pad4[8];
    u32 ramStart;
    u32 ramEnd;
} KaleidoOverlay;

extern KaleidoOverlay *D_801C948C;

/* 17 instructions differ: IDO copies addr to a2 and orders the loads differently from the ROM. */
u32 KaleidoManager_FaultAddrConv(u32 addr, s32 a1) {
    KaleidoOverlay *ovl = D_801C948C;
    u32 start;
    u32 ramStart;
    u32 offset;
    u32 size;

    if (ovl != NULL) {
        start = ovl->start;
        ramStart = ovl->ramStart;
        offset = ramStart - start;
        size = ovl->ramEnd - ramStart;
        if (start != 0 && addr >= start && addr < start + size) {
            return addr + offset;
        }
    }
    return 0;
}
