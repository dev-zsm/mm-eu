#include "types.h"
typedef struct { s16 unk0; s16 unk2; } F;
s16 Rand_S16Offset(s16, s16);

s16 FaceChange_UpdateBlinkingNonHuman(F *f, s16 a1, s16 a2, s16 a3) {
    s32 v;
    s32 d;

    if (f->unk2 == 0) {
        v = 0;
    } else {
        f->unk2--;
        v = f->unk2;
    }
    if (v == 0) {
        f->unk2 = Rand_S16Offset(a1, a2);
    }
    d = f->unk2 - a3;
    if (d > 0) {
        f->unk0 = 0;
    } else if (d == 0) {
        f->unk0 = 1;
    } else {
        f->unk0 = 2;
    }
    return f->unk0;
}
