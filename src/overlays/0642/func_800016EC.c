#include "types.h"

typedef struct {
    u8 pad0[0x148];
    s32 i;
} T;

extern void (*D_80BFF88C[])();

void func_800016EC(T *p) {
    D_80BFF88C[p->i]();
}
