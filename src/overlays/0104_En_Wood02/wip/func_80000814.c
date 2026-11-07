#include "types.h"
typedef struct { u8 pad[0x1C]; s16 x1C; } A;
extern void func_800E0FAC(s32, u8 *, A *, s32);
void EnWood02_Destroy(A *a0, s32 a1) {
    A *p = a0;
    s32 q = a1;
    if (p->x1C < 0xB || p->x1C == 0x1A) {
        func_800E0FAC(q, (u8 *)p + 0x154, p, q);
    }
}
