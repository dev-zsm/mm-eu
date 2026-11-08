// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x138];
    /* 0x138 */ s32 unk138;
} Ea;

typedef struct Eb {
    /* 0x000 */ u8 pad0[0x210];
    /* 0x210 */ Ea *unk210;
    /* 0x214 */ u8 pad214[0x18];
    /* 0x22C */ void *unk22C;
} Eb;

extern u8 D_80AB2340[];
Ea *func_80AB22CC();

void func_80001238(Eb *this) {
    Ea *e = func_80AB22CC(this);

    if (e != NULL && e->unk138 != 0) {
        this->unk22C = D_80AB2340;
        this->unk210 = e;
    }
}
