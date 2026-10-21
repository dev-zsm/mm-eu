// FLAGS: -O2 -g0
#include "types.h"
void func_80088070(s32 a, s32 b, s32 c);
void func_80087224(s32 arg0) {
    func_80088070(arg0 + 8, 0, 1);
}
