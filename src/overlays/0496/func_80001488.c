// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x70];
    /* 0x070 */ f32 unk70[3];
    /* 0x07C */ u8 pad7C[0x3B];
    /* 0x0B7 */ u8 unkB7;
    /* 0x0B8 */ u8 padB8[0x8C];
    /* 0x144 */ u8 unk144[0x20];
} Ea;

s32 func_80137070();
void func_800FEE3C(f32 *, f32, f32);
void func_80B46E84();
void func_80B47804();

void func_80001488(Ea *this, s32 arg1) {
    func_800FEE3C(this->unk70, 0.0f, 0.5f);
    if (func_80137070(this->unk144) != 0) {
        if (this->unkB7 == 0) {
            func_80B47804(this);
            return;
        }
        func_80B46E84(this);
    }
}
