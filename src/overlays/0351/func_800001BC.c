#include "types.h"

typedef struct {
    u8 pad0[0x144];
    void *p;
    s16 t;
} T;

extern u8 D_80A45A70[];

void func_800001BC(T *a, s32 b) {
    if (a->t != 0) {
        a->t--;
    }
    if (a->t == 0) {
        a->p = D_80A45A70;
    }
}
