#include "types.h"

typedef struct { s32 a, b, c; } E12;

extern s32 D_801FB23C;
extern u8 D_801FB230[];
extern E12 D_801F84B0[];
extern void *AudioHeap_Alloc(void *, s32);

void *AudioHeap_AllocPermanent(s32 a0, s32 a1, s32 a2) {
    s32 idx = D_801FB23C;
    u8 *e;

    e = (u8 *)&D_801F84B0[idx];
    if ((*(void **)(e + 0x2D90) = AudioHeap_Alloc(D_801FB230, a2)) == 0) {
        return 0;
    }
    *(s16 *)(e + 0x2D98) = a0;
    *(s16 *)(e + 0x2D9A) = a1;
    *(s32 *)(e + 0x2D94) = a2;
    return *(void **)(e + 0x2D90);
}
