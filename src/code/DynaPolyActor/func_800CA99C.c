#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x76];
    /* 0x76 */ s16 unk76;
    /* 0x78 */ u8 pad78[0x1E];
    /* 0x96 */ s16 unk96;
    /* 0x98 */ u8 pad98[0xC];
} Dyna;

typedef struct {
    /* 0x000 */ s16 unk0;
    /* 0x002 */ u8 pad2[0x30];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x8A];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0xA14];
    /* 0xAD4 */ s16 unkAD4;
} Act;

extern s32 DynaPoly_IsBgIdBgActor(s32);

void DynaPolyActor_UpdateCarriedActorRotY(Dyna *a0, s32 a1, Act *a2) {
    s16 v;

    if (DynaPoly_IsBgIdBgActor(a1)) {
        v = ((Dyna *)((u8 *)a0 + a1 * 100))->unk96 - ((Dyna *)((u8 *)a0 + a1 * 100))->unk76;
        if (a2->unk0 == 0) {
            a2->unkAD4 += v;
        }
        a2->unkBE += v;
        a2->unk32 += v;
    }
}
