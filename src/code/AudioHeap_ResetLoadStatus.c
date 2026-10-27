#include "types.h"

extern struct {
    u8 pad[0x4368];
    u8 a[0x30];
    u8 b[0x30];
    u8 c[0x80];
} D_801F84B0;

void AudioHeap_ResetLoadStatus(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 0x30; i++) {
        if (D_801F84B0.b[i] != 5) {
            D_801F84B0.b[i] = 0;
        }
    }
    for (i = 0; i < 0x30; i++) {
        if (D_801F84B0.a[i] != 5) {
            D_801F84B0.a[i] = 0;
        }
    }
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 4; j++) {
            if (D_801F84B0.c[i * 4 + j] != 5) {
                D_801F84B0.c[i * 4 + j] = 0;
            }
        }
    }
}
