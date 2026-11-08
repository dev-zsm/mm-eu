#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0518.h"
f32 func_8017A844(f32 a);
void func_800B8C4C(u8 *a, s32 b);

void func_8000094C(u8 *a) {
    if ((s32)func_8017A844(2.0f) == 0) {
        func_800B8C4C(a, 0x6918);
    } else {
        func_800B8C4C(a, 0x6919);
    }
}
