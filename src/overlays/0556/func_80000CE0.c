#include "types.h"

extern void func_80BA6BE0();

s32 func_80000CE0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    if (b == 0xF) {
        func_80BA6BE0(f, a);
    }
    return 0;
}
