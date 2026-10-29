#include "types.h"

typedef struct {
    u8 pad0[0x68];
    f32 unk68;
    u8 pad6C[8];
    f32 unk74;
    f32 unk78;
} Ovl0175Actor;

void func_80000A6C(Ovl0175Actor *a) {
    a->unk68 += a->unk74;
    if (a->unk68 < a->unk78) {
        a->unk68 = a->unk78;
    }
}
