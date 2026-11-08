// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ u8 unk144[0x44];
    /* 0x188 */ void *unk188;
    /* 0x18C */ u8 pad18C[0x118];
    /* 0x2A4 */ s16 unk2A4;
    /* 0x2A6 */ s16 unk2A6;
    /* 0x2A8 */ u8 pad2A8[2];
    /* 0x2AA */ s16 unk2AA;
} Ea;

extern u8 D_80A1B33C[];
extern u8 D_80A1C2EC[];
void func_800B8C4C();
void func_800BD9E0();

void func_8000058C(Ea *this) {
    this->unk2A4 = 0;
    this->unk2AA = 0x12C;
    if (this->unk2A6 == 1) {
        func_800B8C4C(this, 0x38C6);
    }
    func_800BD9E0(this->unk144, D_80A1C2EC, 1);
    this->unk188 = D_80A1B33C;
}
