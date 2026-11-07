#include "types.h"
typedef struct { u8 pad0[0x68]; f32 f68; u8 pad1[0x160-0x6C]; void *p160; u8 pad2[0x17C-0x164]; u8 b17C; u8 b17D; } A;
extern u8 D_80B640B8;
void func_80000900(A *a) {
    a->b17C &= 0xFFF8;
    a->b17C |= 4;
    a->b17D = 1;
    a->p160 = &D_80B640B8;
    a->f68 = 0.0f;
}
