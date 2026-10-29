#include "types.h"

typedef struct {
    u8 pad0[0x98];
    s32 unk98;
    s32 unk9C;
} S;

extern void func_800B8284();

void func_80001304(S *s, s32 a1) {
    func_800B8284(s, a1, s->unk98, s->unk9C, -1);
}
