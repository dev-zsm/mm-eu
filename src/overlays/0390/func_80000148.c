#include "types.h"

typedef struct {
    u8 pad[0x3BE];
    s16 f3BE;
} A;

extern void func_80A99A40(A *, s32, s32, f32);

void func_80000148(A *a, s32 b) {
    if (b != a->f3BE) {
        func_80A99A40(a, b, 0, -5.0f);
    }
}
