#include "types.h"
typedef struct { u8 pad0[0x70]; f32 f70; u8 pad1[0x24C-0x74]; s32 t; } A;
extern void func_80A4BF2C();
void func_80000F54(A *a, s32 b) {
    a->t -= 1;
    if (a->t <= 0) {
        a->f70 = 0.0f;
        func_80A4BF2C();
    }
}
