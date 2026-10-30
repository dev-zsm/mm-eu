#include "types.h"

extern void func_80BCB1A8();
extern u8 D_80BCBC90[];

typedef struct { u8 pad0[0x254]; void *unk254; u8 pad258[0x274 - 0x258]; s16 unk274; u8 pad276[0x288 - 0x276]; s16 unk288; } A;

void func_80000CE0(A *this) {
    func_80BCB1A8(this, 2);
    this->unk274 = 0;
    this->unk288 = 3;
    this->unk254 = D_80BCBC90;
}
