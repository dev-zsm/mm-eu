#include "types.h"
extern void func_80BC06D0();
typedef struct { u8 pad0[0x15C]; f32 a; u8 pad1[0xCC]; f32 b; } A;
void func_800008B4(A *a, s32 b) {
    f32 x = a->a;
    if (x >= a->b) {
        func_80BC06D0();
    }
}
