// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ob {
    /* 0x000 */ s16 unk0;
    /* 0x002 */ u8 pad2[0x12A];
    /* 0x12C */ struct Ob *unk12C;
} Ob;

typedef struct Pl {
    /* 0x0000 */ u8 pad0[0x1CE4];
    /* 0x1CE4 */ Ob *unk1CE4;
} Pl;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x274];
    /* 0x274 */ Ob *unk274;
    /* 0x278 */ Ob *unk278;
} Ea;

void func_80BCEC98();

void func_80000374(Ea *this, Pl *play) {
    Ob *p = play->unk1CE4;

    if (p != NULL) {
        do {
            if (p->unk0 == 0x26B) {
                this->unk274 = p;
            } else if (p->unk0 == 0x26C) {
                this->unk278 = p;
            }
            p = p->unk12C;
        } while (p != NULL);
    }
    func_80BCEC98(this, play);
}
