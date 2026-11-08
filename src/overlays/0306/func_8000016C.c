// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x29C];
    /* 0x29C */ u8 unk29C;
} Ea;

extern f32 D_80A0E4C0;
f32 func_8008704C();

void func_8000016C(Ea *this) {
    u8 t = this->unk29C;
    u8 n;

    if (t != 0) {
        n = t + 1;
        this->unk29C = n;
        if ((n & 0xFF) == 4) {
            this->unk29C = 0;
        }
    } else if (func_8008704C() < D_80A0E4C0) {
        this->unk29C = 1;
    }
}
