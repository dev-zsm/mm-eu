#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x10];
} BlureSpace;

typedef struct {
    BlureSpace elements[16];
    u8 pad180[0x1E];
    u8 numElements;
} Blure;

void EffectBlure_AddSpace(Blure *this) {
    BlureSpace *space;

    if (this != NULL && this->numElements < 16) {
        space = &this->elements[this->numElements];
        space->unk0 = 0;
        space->unk4 = 1;
        this->numElements++;
    }
}
