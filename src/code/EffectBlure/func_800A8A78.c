// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8[6];
    s16 unk14;
    s16 unk16;
} Elem;
typedef struct {
    Elem elems[16];
    u8 pad180[0x1E];
    u8 unk19E;
} Blure;
void EffectBlure_InitElements(Blure *this) {
    s32 i;

    this->unk19E = 0;
    for (i = 0; i < 16; i++) {
        this->elems[i].unk0 = 2;
        this->elems[i].unk8[0] = 0;
        this->elems[i].unk8[1] = 0;
        this->elems[i].unk8[2] = 0;
        this->elems[i].unk8[3] = 0;
        this->elems[i].unk8[4] = 0;
        this->elems[i].unk8[5] = 0;
        this->elems[i].unk4 = 0;
        this->elems[i].unk14 = 0;
    }
}
