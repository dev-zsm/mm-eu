#include "types.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
} Elem;

typedef struct {
    u8 pad0[8];
    s32 numElements;
    Elem elements[1];
    u8 pad[0x490 - 0x30];
    f32 unk490;
    u8 pad494[0x4BC - 0x494];
    s32 unk4BC;
    s32 unk4C0;
} Spark;

s32 EffectSpark_Update(Spark *arg0) {
    s32 i;
    Elem *e;


    for (i = 0; i < arg0->numElements; i++) {
        e = &arg0->elements[i];
        e->unkC += e->unk0;
        e->unk10 += e->unk4;
        e->unk14 += e->unk8;
        e->unk4 += arg0->unk490;
        e->unk1E += e->unk18;
        e->unk20 += e->unk1A;
        e->unk22 += e->unk1C;
    }
    arg0->unk4BC++;
    if (arg0->unk4C0 < arg0->unk4BC) {
        return 1;
    }
    return 0;
}
