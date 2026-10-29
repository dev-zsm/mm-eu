#include "types.h"

extern void func_80BB6210(void *a0, s16 a1, u8 a2, f32 a3);

void func_80000390(void *a0, s16 a1, u8 a2) {
    func_80BB6210(a0, a1, a2, 5.0f);
}
