// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 start;
    u8 pad4[8];
    u32 mappedStart;
    u32 mappedEnd;
    u8 pad14[0x1C];
} AddrMapping;

extern AddrMapping D_801BE440[];
extern s32 D_801BE590;

u32 Graph_FaultAddrConv(u32 addr, s32 arg1) {
    s32 i;

    for (i = 0; i < D_801BE590; i++) {
        u32 start = D_801BE440[i].start;
        u32 mappedStart = D_801BE440[i].mappedStart;
        u32 offset = mappedStart - start;
        u32 size = D_801BE440[i].mappedEnd - mappedStart;

        if (start != 0 && addr >= start && addr < start + size) {
            return addr + offset;
        }
    }
    return 0;
}
