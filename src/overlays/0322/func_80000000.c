// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x00 */ u8 pad0[0x38];
    /* 0x38 */ s8 unk38;
} Ea;

s8 func_800F1E68();

void func_80000000(Ea *this, s32 n) {
    while (n > 0) {
        if (this->unk38 == -1) {
            return;
        }
        this->unk38 = func_800F1E68(this->unk38);
        n--;
    }
}
