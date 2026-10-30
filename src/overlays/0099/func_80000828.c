#include "types.h"

extern void func_801377D0();
extern u8 D_6000168[];
extern u8 D_808BD12C[];

typedef struct { u8 pad0[0x144]; u8 unk144; u8 pad145[0x188 - 0x145]; void *unk188; u8 pad18C[4]; s16 unk190; u8 pad192[2]; s16 unk194; } A;

void func_80000828(A *this) {
    func_801377D0(&this->unk144, D_6000168, this);
    this->unk190 = this->unk194;
    this->unk188 = D_808BD12C;
}
