// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x28];
    /* 0x028 */ f32 unk28;
    /* 0x02C */ u8 pad2C[0x2C];
    /* 0x058 */ f32 unk58;
    /* 0x05C */ f32 unk5C;
    /* 0x060 */ u8 pad60[8];
    /* 0x068 */ f32 unk68;
    /* 0x06C */ u8 pad6C[8];
    /* 0x074 */ f32 unk74;
    /* 0x078 */ u8 pad78[0x44];
    /* 0x0BC */ s16 unkBC;
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[4];
    /* 0x0C4 */ f32 unkC4;
    /* 0x0C8 */ u8 padC8[0x74];
    /* 0x13C */ void *unk13C;
    /* 0x140 */ u8 pad140[0xC0];
    /* 0x200 */ void *unk200;
    /* 0x204 */ u8 pad204[0x14];
    /* 0x218 */ f32 unk218;
    /* 0x21C */ u8 pad21C[0x77];
    /* 0x293 */ u8 unk293;
} Ea;

extern u8 D_80B493AC[];
extern u8 D_80B47F94[];
void func_800B8C4C();

void func_80001C18(Ea *this) {
    this->unk13C = D_80B493AC;
    this->unkC4 = 0.0f;
    this->unkBC = 0;
    this->unkBE = 0;
    this->unk74 = 0.0f;
    this->unk68 = 0.0f;
    this->unk293 = 0;
    this->unk58 = 0.0f;
    this->unk5C = 0.0f;
    this->unk218 = this->unk28;
    func_800B8C4C(this, 0x28E0);
    this->unk200 = D_80B47F94;
}
