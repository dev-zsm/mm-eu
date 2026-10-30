#include "types.h"
extern s32 func_80137C58(u8 *, f32);
extern void func_800B8C4C();
void func_800008C8(u8 *a0, f32 a1) {
    if (func_80137C58(a0 + 0x14C, a1) != 0) {
        func_800B8C4C(a0, 0x2910);
    }
}
