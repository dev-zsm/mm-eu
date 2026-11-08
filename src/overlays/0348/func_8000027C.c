// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0xBC];
    /* 0x0BC */ s16 unkBC;
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ s16 unkC0;
    /* 0x0C2 */ u8 padC2[0x14A];
    /* 0x20C */ u8 unk20C[0xC];
    /* 0x218 */ u8 unk218[0xC];
    /* 0x224 */ u8 unk224[1];
} Ea;

void func_80181A3C(s16, s32);
void func_80181508(s16, s32);
void func_80181D88(s16, s32);
void func_80182CA0(f32, u8 *);
void func_80182C54(f32, u8 *);
void func_80182C08(f32, u8 *);

void func_8000027C(Ea *this) {
    func_80181A3C(this->unkBE, 0);
    func_80181508(this->unkBC, 1);
    func_80181D88(this->unkC0, 1);
    func_80182CA0(1.0f, this->unk20C);
    func_80182C54(1.0f, this->unk218);
    func_80182C08(1.0f, this->unk224);
}
