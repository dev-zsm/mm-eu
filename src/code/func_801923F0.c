#include "types.h"

typedef struct {
    u8 pad0[0x160];
} Slot;

typedef struct {
    u8 unk0;
    u8 pad1[0x57];
} Sub;

extern Slot D_801F84B0[4];

void AudioLoad_InitAsyncLoads(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            ((Sub *)((u8 *)&D_801F84B0[i] + 0x1790))[j].unk0 = 0;
        }
    }
}
