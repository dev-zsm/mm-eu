#include "types.h"

extern s32 func_8082D77C();
extern void func_800B8BDC();

void func_80000664(void *a0, s32 a1) {
    s32 v;

    v = func_8082D77C(a0, a1 & 0xFFFF);
    func_800B8BDC(a0, v & 0xFFFF);
}
