#include "types.h"
void View_SetPerspective(void *a0, f32 a1, f32 a2, f32 a3) {
    *(f32 *)((u8 *)a0 + 0x18) = a1;
    *(f32 *)((u8 *)a0 + 0x1C) = a2;
    *(f32 *)((u8 *)a0 + 0x20) = a3;
    *(u32 *)((u8 *)a0 + 0x160) |= 4;
}
