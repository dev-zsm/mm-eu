#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x148];
    /* 0x148 */ u8 unk148;
    /* 0x149 */ u8 pad149[0xC7];
    /* 0x210 */ s32 unk210;
} Ovl0481Actor;

extern void func_800E0FAC();

void func_80000200(Ovl0481Actor *this, s32 play) {
    if (this->unk210 == 0) {
        func_800E0FAC(play, &this->unk148);
    }
}
