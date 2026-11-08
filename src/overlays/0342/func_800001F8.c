// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ void *unk144;
    /* 0x148 */ u8 pad148[0x44];
    /* 0x18C */ u8 unk18C[4];
    /* 0x190 */ s32 unk190;
    /* 0x194 */ s32 unk194;
    /* 0x198 */ s16 unk198;
    /* 0x19A */ u8 pad19A[6];
    /* 0x1A0 */ s32 unk1A0;
} Ea;

extern u8 D_80A35CFC[];
s32 func_8010BD58();
void func_8013B284();

void func_800001F8(Ea *this, s32 arg1) {
    if (func_8010BD58(this, arg1, this->unk190, this->unk1A0, &this->unk194) != 0) {
        func_8013B284(this->unk18C, 3, 7);
        this->unk194 = 0;
        this->unk198 = 0;
        this->unk144 = D_80A35CFC;
    }
}
