// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x38];
    /* 0x038 */ s8 unk38;
    /* 0x039 */ u8 pad39[0xD3F];
    /* 0xD78 */ void *unkD78;
    /* 0xD7C */ u8 padD7C[0x11];
    /* 0xD8D */ s8 unkD8D;
} Ea;

extern u8 D_801E7E1B;
extern u8 D_80A265A8[];
extern u8 D_80A265C0[];
extern u8 D_80A265CC[];
s32 func_80A241F4();

void func_80000D54(Ea *this, s32 arg1) {
    if (func_80A241F4(arg1) == 0) {
        this->unkD78 = D_80A265CC;
    } else if (D_801E7E1B & 8) {
        this->unkD78 = D_80A265C0;
    } else {
        this->unkD78 = D_80A265A8;
    }
    this->unkD8D = this->unk38;
}
