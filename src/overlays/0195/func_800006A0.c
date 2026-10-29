#include "types.h"

typedef struct {
    u8 pad0[0x11C];
    u8 unk11C;
    u8 pad11D[0x40D];
    s16 unk52A;
    u8 pad52C[0x96];
    u16 unk5C2;
} Actor195;

void func_800006A0(Actor195 *a) {
    if (a->unk52A == 0) {
        a->unk5C2 |= 8;
        a->unk52A = 0x78;
        a->unk11C = 0;
    }
}
