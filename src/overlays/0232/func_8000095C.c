#include "types.h"
extern s32 func_80137C58(void *, f32);
extern void func_800B8C4C();
void func_8000095C(u8 *a, f32 b) {
    if (func_80137C58(a + 0x14C, b)) {
        func_800B8C4C(a, 0x290B);
    }
}
