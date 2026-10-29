#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x50];
    u8 unk55;
    u8 pad56[0x3F];
    u8 unk95;
} Ovl0100Sub;

typedef struct {
    u8 pad0[0x3A0];
    Ovl0100Sub *unk3A0;
} Ovl0100Actor;

void func_80000358(Ovl0100Actor *a) {
    a->unk3A0->unk4 = 1;
    a->unk3A0->unk55 |= 1;
    a->unk3A0->unk95 |= 1;
}
