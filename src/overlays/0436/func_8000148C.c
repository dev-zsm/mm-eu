// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x70];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x11C];
    /* 0x190 */ u8 unk190[0x44];
    /* 0x1D4 */ void *unk1D4;
} Ea;

extern u8 D_80AD0A80[];
extern u8 D_80ACFC44[];
void func_800BD9E0();
void func_80ACE7F4();
void func_80ACE87C();

void func_8000148C(Ea *this) {
    this->unk70 = 2.0f;
    func_800BD9E0(this->unk190, D_80AD0A80, 1);
    func_80ACE7F4(this, 1);
    func_80ACE87C(1, 1);
    this->unk1D4 = D_80ACFC44;
}
