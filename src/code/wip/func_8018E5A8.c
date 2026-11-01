// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x3920];
    s32 unk3920;
    u8 pad3924[0x392C - 0x3924];
    s32 unk392C;
    u8 pad3930[0x4334 - 0x3930];
    s32 unk4334;
} Heap;

extern u8 D_801FAEA0;
extern u8 D_801FB3C0;
extern s32 D_801FB3C8;
extern u8 D_801FBDD4;
extern Heap D_801F84B0;
extern void *AudioHeap_AllocAttemptExternal(void *, u32);
extern void AudioHeap_InitPool(void *, void *, u32);

void AudioHeap_InitSampleCaches(u32 persistentSize, u32 temporarySize) {
    void *ram;

    ram = AudioHeap_AllocAttemptExternal(&D_801FAEA0, persistentSize);
    if (ram == NULL) {
        D_801FB3C8 = 0;
    } else {
        AudioHeap_InitPool(&D_801FB3C0, ram, persistentSize);
    }
    ram = AudioHeap_AllocAttemptExternal(&D_801FAEA0, temporarySize);
    if (ram == NULL) {
        D_801F84B0.unk392C = 0;
    } else {
        AudioHeap_InitPool(&D_801FBDD4, ram, temporarySize);
    }
    D_801F84B0.unk3920 = 0;
    D_801F84B0.unk4334 = 0;
}
