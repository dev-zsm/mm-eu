#include "types.h"

typedef struct {
    u32 start;
    u32 ptr;
    u32 size;
    u8 medium;
} A;

typedef struct {
    u32 pad0 : 4;
    u32 medium : 2;
    u32 pad1 : 26;
    u32 addr;
} B;

extern s32 D_801F4960;

void AudioHeap_ChangeStorage(A *arg0, B *arg1) {
    u32 medium;
    u32 start;
    u32 end;
    u32 addr;

    if (arg1 != NULL) {
        medium = arg1->medium;
        if ((arg0->medium == medium || D_801F4960 != 1) && (medium == 0 || D_801F4960 != 0)) {
            start = arg0->start;
            addr = arg1->addr;
            end = start + arg0->size;
            if (!(addr < start) && addr < end) {
                arg1->addr = addr - start + arg0->ptr;
                if (D_801F4960 == 0) {
                    *(u8 *)arg1 = ((arg0->medium << 2) & 0xC) | (*(u8 *)arg1 & 0xFFF3);
                    return;
                }
                *(u8 *)arg1 = *(u8 *)arg1 & 0xFFF3;
            }
        }
    }
}
