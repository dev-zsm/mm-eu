#include "types.h"
extern s64 D_801C0440;
typedef struct { u8 pad0[0x1020]; s64 unk1020; u8 pad1[0x28]; s64 unk1050; u8 pad2[0x28]; s64 unk1080; u8 pad3[0x28]; s64 unk10B0; } S;
extern u8 D_801E6EF0[];
extern s64 func_800905C0(s16, s16, void *);
void func_8010EA40(s16 a0, s16 a1) {
    S *b; s64 t;
    D_801E6EF0[a1 + 0x101A] = 1;
    b = (S *)(D_801E6EF0 + a1 * 8);
    t = a0 * 100;
    b->unk1080 = t;
    b->unk1050 = t;
    b->unk1020 = func_800905C0(a0, a1, b);
    b->unk10B0 = 0;
    D_801C0440 = 0;
}
