#include "types.h"

typedef struct {
    u8 pad0[0x15];
    u8 unk15;
    u8 pad16[2];
    void *unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
} TransitionCircle;

extern void func_800897D0(void *ptr, s32 size);
extern u8 D_801C6A80[];

void TransitionCircle_Init(TransitionCircle *this) {
    func_800897D0(this, 0x20);
    this->unk15 = 1;
    this->unk18 = D_801C6A80;
    this->unk1C = 6;
    this->unk1D = 6;
    this->unk1E = 4;
    this->unk1F = 0;
}
