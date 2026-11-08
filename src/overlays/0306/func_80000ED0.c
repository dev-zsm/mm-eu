// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ s16 unk1C;
    /* 0x01E */ u8 pad1E[0x14];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x3C];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x4A];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0x84];
    /* 0x144 */ u8 unk144[0x154];
    /* 0x298 */ void *unk298;
} Ea;

extern u8 D_600823C[];
extern u8 D_80A0D17C[];
void func_801378E0();

void func_80000ED0(Ea *this) {
    func_801378E0(&this->unk144, D_600823C);
    this->unk70 = 1.0f;
    this->unk32 = this->unkBE;
    this->unk1C = 1;
    this->unk298 = D_80A0D17C;
}
