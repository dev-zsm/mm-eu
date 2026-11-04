// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Collider_ResetOCBase(s32);
void Collider_ResetJntSphElementOC(s32, u32);

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    u32 unk1C;
} CollSet;

s32 Collider_ResetJntSphOC(s32 a0, CollSet *a1) {
    CollSet *s1 = a1;
    u32 s0;

    Collider_ResetOCBase(a0);
    s0 = a1->unk1C;
    if (s0 < (u32)((s32)s0 + (a1->unk18 << 6))) {
        do {
            Collider_ResetJntSphElementOC(a0, s0);
            s0 += 0x40;
        } while (s0 < (u32)(s1->unk1C + (s1->unk18 << 6)));
    }
    return 1;
}
