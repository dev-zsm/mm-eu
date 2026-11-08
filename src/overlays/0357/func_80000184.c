// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ u8 unk144[0xC8];
    /* 0x20C */ void *unk20C;
    /* 0x210 */ u8 pad210[0xC];
    /* 0x21C */ s16 unk21C;
} Ea;

extern u8 D_6002B6C[];
extern u8 D_80A4C808[];
s32 func_80134AE8();
void func_80137788(u8 *, u8 *, f32, f32, f32, s32, f32);

void func_80000184(Ea *this) {
    func_80137788(this->unk144, D_6002B6C, 1.0f, 0.0f, func_80134AE8(D_6002B6C), 0, -10.0f);
    this->unk21C = 0;
    this->unk20C = D_80A4C808;
}
