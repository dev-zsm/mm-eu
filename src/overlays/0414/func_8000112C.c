// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ob {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ f32 unk8;
    /* 0x00C */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x118];
    /* 0x12C */ struct Ob *unk12C;
} Ob;

typedef struct Pl {
    /* 0x0000 */ u8 pad0[0x1CF0];
    /* 0x1CF0 */ Ob *unk1CF0;
} Pl;

Ob *func_8000112C(Ob *arg0, Pl *play) {
    Ob *p = play->unk1CF0;

    while (p != NULL) {
        if (p->unk8 == arg0->unk8 && p->unkC == arg0->unkC && p->unk10 == arg0->unk10) {
            return p;
        }
        p = p->unk12C;
    }
    return NULL;
}
