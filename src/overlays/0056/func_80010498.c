#include "types.h"
typedef struct { u8 pad0[0x38]; f32 a38; } Q;
typedef struct { u8 pad0[0xA68]; Q* q; } P;
void func_8083D410(s32, P *, f32, f32, f32, f32);
void func_80010498(s32 a, P *b) {
    f32 y = b->q->a38;
    func_8083D410(a, b, 26.800001f, y + 5.0f, y + 15.0f, 0.0f);
}
