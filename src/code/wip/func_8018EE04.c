#include "types.h"

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
} S0;
typedef struct {
    u32 pad : 4;
    u32 f : 2;
    u32 rest : 26;
    u32 unk4;
} S1;

extern s32 D_801F4960;

void AudioHeap_ChangeStorage(S0 *a, S1 *b) {
    u32 v1;
    u32 a3;
    u32 f;

    if (b != 0 && (f = b->f, (a->unkC == f || D_801F4960 != 1)) && (f == 0 || D_801F4960 != 0) &&
        (v1 = a->unk0, a3 = b->unk4, !(a3 < v1)) && a3 < v1 + a->unk8) {
        b->unk4 = a3 - v1 + a->unk4;
        if (D_801F4960 == 0) {
            *(u8 *)b = ((a->unkC << 2) & 0xC) | (*(u8 *)b & 0xFFF3);
            return;
        }
        *(u8 *)b = *(u8 *)b & 0xFFF3;
    }
}
