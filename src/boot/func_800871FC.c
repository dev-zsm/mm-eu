// FLAGS: -O2 -g0
#include "types.h"
void func_80087CB0(s32 a, s32 b, s32 c);
void func_800871FC(s32 arg0) {
    func_80087CB0(arg0 + 8, 0, 1);
}
