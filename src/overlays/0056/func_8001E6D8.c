#include "types.h"
#include "generated/overlays/0056.h"
s32 func_80836DE0(s32, s32, f32, s32);
void func_800B8BDC();
s32 func_8001E6D8(s32 a, s32 b) {
    if (func_80836DE0(a, b, 3.0f, 0x1F4) != 0) {
        func_800B8BDC(b, 0x2889);
        return 1;
    }
    return 0;
}
