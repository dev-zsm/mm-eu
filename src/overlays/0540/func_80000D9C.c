#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0540.h"
s32 func_80B88EC8(s32 a, s32 b);
void func_800B701C(s32 a, s32 b, s32 c);

s32 func_80000D9C(s32 a, s32 play) {
    if (func_80B88EC8(a, play) != 0) {
        func_800B701C(play, 0, 6);
        return 1;
    }
    return 0;
}
