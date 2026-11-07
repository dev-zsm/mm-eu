#include "types.h"

typedef struct {
    u8 pad0[0x1D6];
    s16 unk1D6;
    s16 unk1D8;
    s16 unk1DA;
} Actor159;

extern void func_809237C4();

void func_800004E0(Actor159 *a) {
    s16 v = a->unk1D8;

    a->unk1D6 = v;
    a->unk1D8 = v + a->unk1DA;
    func_809237C4(a);
}
