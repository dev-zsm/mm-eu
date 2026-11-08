// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x2AC];
    /* 0x2AC */ u8 unk2AC;
} Ea;

extern f32 D_80AC4890;
f32 func_8008704C();

void func_800001FC(Ea *this) {
    u8 t = this->unk2AC;
    u8 n;

    if (t != 0) {
        n = t + 1;
        this->unk2AC = n;
        if ((n & 0xFF) == 4) {
            this->unk2AC = 0;
        }
    } else if (func_8008704C() < D_80AC4890) {
        this->unk2AC = this->unk2AC + 1;
    }
}
