// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct V3 {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct Ob {
    /* 0x00 */ u8 pad0[0x5C];
    /* 0x5C */ V3 unk5C;
} Ob;

typedef struct Pl {
    /* 0x000 */ u8 pad0[0x800];
    /* 0x800 */ Ob *unk800[1];
    /* 0x804 */ u8 pad804[0xC];
    /* 0x810 */ s16 unk810;
} Pl;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ V3 unk24;
    /* 0x030 */ u8 pad30[0x114];
    /* 0x144 */ s16 unk144;
} Ea;

void func_800B6490();

void func_8000008C(Ea *this, Pl *play) {
    s16 t = this->unk144;

    this->unk24 = play->unk800[play->unk810]->unk5C;
    if (t < 0x64) {
        this->unk144 = t + 1;
    } else {
        func_800B6490(this);
    }
}
