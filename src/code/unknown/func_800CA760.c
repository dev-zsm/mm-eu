#include "types.h"

extern void func_800CA480(void *a0, void *a1, f32 a2, f32 a3, s32 a4, s32 a5, s32 *out);

void func_800CA760(void *a0, void *a1, f32 a2, f32 a3, s32 a4, s32 a5) {
    s32 result;

    func_800CA480(a0, a1, a2, a3, a4, a5, &result);
}
