// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ob {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ s16 unk1C;
    /* 0x01E */ u8 pad1E[0x10E];
    /* 0x12C */ struct Ob *unk12C;
} Ob;

Ob *func_8013DD10();
void func_800B6490();

void func_800000F0(s32 arg0) {
    Ob *p = NULL;

    do {
        p = func_8013DD10(arg0, p, 8, 0x1A5);
        if (p != NULL) {
            if ((p->unk1C & 0xF) == 1) {
                func_800B6490(p);
            }
            p = p->unk12C;
        }
    } while (p != NULL);
}
