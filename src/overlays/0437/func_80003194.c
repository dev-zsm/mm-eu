// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x188];
    /* 0x188 */ void (*unk188)(struct Ea *, s32);
    /* 0x18C */ u8 pad18C[0x18A];
    /* 0x316 */ s16 unk316;
    /* 0x318 */ s16 unk318;
} Ea;

f32 func_800FEB84();

void func_80003194(Ea *this, s32 arg1) {
    this->unk316 += 0x46C8;
    this->unk318 = func_800FEB84(this->unk316) * 900.0f;
    this->unk188(this, arg1);
}
