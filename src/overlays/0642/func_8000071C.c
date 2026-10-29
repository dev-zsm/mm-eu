#include "types.h"

typedef struct {
    u8 pad0[0x16C];
    s16 unk16C;
} Ovl0642Actor;

extern void func_800B8D94();

void func_8000071C(Ovl0642Actor *a, s32 b) {
    a->unk16C += 0x258;
    func_800B8D94(a, 0x21B5);
}
