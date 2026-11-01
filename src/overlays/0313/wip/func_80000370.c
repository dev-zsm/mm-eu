#include "types.h"

typedef struct {
    u8 pad0[0x58];
    f32 f58;
    f32 f5C;
    f32 f60;
    u8 pad1[0x144 - 0x64];
    void *f144;
} A;

extern f32 D_80A16914;
extern f32 D_80A16918;
extern u8 D_80A13E70[];

void func_80000370(A *a) {
    f32 t = D_80A16914;

    a->f58 = t;
    a->f60 = t;
    a->f5C = D_80A16918;
    a->f144 = D_80A13E70;
}
