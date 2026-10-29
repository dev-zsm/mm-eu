#include "types.h"

extern void func_80B25BA4(s32, s32, u16);

void func_800006BC(s32 a, s32 b, u16 c) {
    c += 1;
    func_80B25BA4(a, b, c);
}
