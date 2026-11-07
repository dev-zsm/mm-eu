#include "types.h"

typedef struct {
    u8 pad0[0x1A4];
    void *p;
    u8 pad1[0x1C8 - 0x1A8];
    s16 v;
} T;

extern u8 D_809270F4[];
extern void func_809235A0();

void func_80003D2C(T *a) {
    a->p = D_809270F4;
    func_809235A0(a, 0);
    a->v = 0x64;
}
