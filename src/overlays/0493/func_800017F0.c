#include "types.h"

extern void func_8013E768();
extern u8 D_80B4183C[];

typedef struct { u8 pad0[0x144]; void *unk144; u8 pad148[0x356 - 0x148]; u8 unk356; } A;

void func_800017F0(A *this, s32 play) {
    func_8013E768(this, &this->unk356, 2);
    this->unk144 = D_80B4183C;
}
