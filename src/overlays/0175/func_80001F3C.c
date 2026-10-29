#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
} Ovl0175Actor;

extern void (*D_809442A0[])();

void func_80001F3C(Ovl0175Actor *a) {
    D_809442A0[a->unk1C & 1](a);
}
