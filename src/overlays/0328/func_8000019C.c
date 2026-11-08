// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Eb {
    /* 0x0 */ u8 pad0[2];
    /* 0x2 */ u16 unk2;
} Eb;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0xD78];
    /* 0xD78 */ Eb *unkD78;
    /* 0xD7C */ u8 padD7C[0x10];
    /* 0xD8C */ u8 unkD8C;
} Ea;

void func_80151DF4();

s32 func_8000019C(Ea *this, s32 arg1) {
    if ((this->unkD8C == 0 ? 0 : --this->unkD8C) == 0) {
        func_80151DF4(arg1, this->unkD78->unk2, 0, this);
        return 1;
    }
    return 0;
}
