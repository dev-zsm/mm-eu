#include "types.h"
typedef struct { u8 pad[0xBE]; s16 xBE; } A;
extern void func_808331C8(void *, A *, s32, f32, f32, s32, s32);
void func_80013B54(void *a0, A *a1) {
    func_808331C8(a0, a1, 1, 2.0f, 2.0f, a1->xBE + 0x8000, 0);
}
