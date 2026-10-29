#include "types.h"

typedef struct {
    u8 pad0[0x144];
    void *p;
    u8 pad1[2];
    s16 t;
} T;

extern u8 D_80991400[];

void func_800001DC(T *a, s32 b) {
    if (a->t != 0) {
        a->t--;
    }
    if (a->t == 0) {
        a->p = D_80991400;
    }
}
