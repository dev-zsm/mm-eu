// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
} VisMono;

void func_800897D0(void *, s32);

void VisMono_Init(VisMono *this) {
    func_800897D0(this, 0x18);
    this->unk0 = 0;
    this->unk4 = 0;
    this->unk8 = 0xFF;
    this->unk9 = 0xFF;
    this->unkA = 0xFF;
    this->unkB = 0xFF;
    this->unkC = 0;
    this->unkD = 0;
    this->unkE = 0;
    this->unkF = 0;
}
