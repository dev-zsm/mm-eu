// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x190];
    /* 0x190 */ u8 unk190[0x10];
    /* 0x1A0 */ s32 unk1A0;
    /* 0x1A4 */ u8 pad1A4[0x17A];
    /* 0x31E */ s16 unk31E;
} Ea;

extern u8 D_80BBF258[];
s32 func_80137C58();
void func_800BD9E0();

void func_80002030(Ea *this, s32 arg1) {
    if (this->unk31E == 1) {
        if (func_80137C58(this->unk190, this->unk1A0) != 0) {
            this->unk31E = 0;
            func_800BD9E0(this->unk190, D_80BBF258, 0xC);
        }
    }
}
