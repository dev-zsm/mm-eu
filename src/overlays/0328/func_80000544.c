// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0xD78];
    /* 0xD78 */ u8 *unkD78;
} Ea;

extern s32 (*D_80A26410[])(struct Ea *, s32);
s32 func_80A23A3C();

s32 func_80000544(Ea *this, s32 arg1) {
    s32 r = D_80A26410[*this->unkD78](this, arg1);

    if (r != 0) {
        this->unkD78 += r * 4;
        return func_80A23A3C(this, arg1);
    }
    return 0;
}
