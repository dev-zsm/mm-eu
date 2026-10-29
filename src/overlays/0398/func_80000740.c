#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 f1C;
    u8 pad1[0xC0 - 0x1E];
    s16 fC0;
    u8 pad2[0x188 - 0xC2];
    void *f188;
    u8 pad3[0x25C - 0x18C];
    s16 f25C;
    u8 pad4[0x270 - 0x25E];
    s16 f270;
} A;

extern u8 D_80AA670C[];

void func_80000740(A *a) {
    a->f270 = a->f1C & 0x3FF;
    a->f25C = a->fC0;
    a->fC0 = 0;
    a->f188 = D_80AA670C;
}
