#include "types.h"

typedef struct {
    u8 pad0[0xA70];
    s32 flags;
} T;

extern void func_800B8BDC(void *, u16);

void func_80000760(T *a, u16 b) {
    func_800B8BDC(a, b);
    a->flags |= 8;
}
