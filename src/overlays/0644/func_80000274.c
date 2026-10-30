#include "types.h"

typedef struct { u8 pad0[0x13C]; void *unk13C; u8 pad1[0x2E4 - 0x140]; s16 unk2E4; } A;
extern void func_800B6564(void *, f32);
extern u8 D_80C0088C[];

void func_80000274(A *a0) {
    a0->unk13C = D_80C0088C;
    if (a0->unk2E4 == 1) {
        func_800B6564(a0, 0.02f);
    }
}
