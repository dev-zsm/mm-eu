#include "types.h"

typedef struct { u8 r, g, b, a; } Color;
typedef struct { u8 pad0[0x18]; } Elem;
typedef struct {
    Elem elems[64];
    s16 unk600;
    s16 unk602;
    s16 unk604;
    Color color;
} TireMark;
typedef struct {
    s16 unk0;
    s16 unk2;
    Color color;
} TireMarkInit;

extern void EffectTireMark_InitElement(Elem *e);

void EffectTireMark_Init(TireMark *this, TireMarkInit *init) {
    s32 i;

    for (i = 0; i != 0x600; i += 0x18) {
        EffectTireMark_InitElement((Elem *)((u8 *)this + i));
    }
    this->unk600 = init->unk0;
    this->unk602 = 0;
    if (init->unk2 >= 0x3F) {
        this->unk604 = 0x3E;
    } else {
        this->unk604 = init->unk2;
    }
    this->color = init->color;
}
