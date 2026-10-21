// FLAGS: -O2 -g0
#include "types.h"
void func_800871FC(s32 a0, u32 a1);
void func_80087224(s32 a0);
void *func_80087394(s32 a0, u32 a1);
void *func_8008743C(s32 a0, u32 a1) {
    void *ret;
    func_800871FC(a0, a1);
    ret = func_80087394(a0, a1);
    func_80087224(a0);
    return ret;
}
