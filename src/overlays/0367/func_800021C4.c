#include "types.h"
typedef struct { u8 pad0[0x15C]; f32 f15C; u8 pad1[0x35C-0x160]; f32 f35C; } A;
extern void func_80A61EFC();
void func_800021C4(A *a, s32 b) {
    f32 x = a->f15C;
    if (a->f35C <= x) {
        func_80A61EFC();
    }
}
