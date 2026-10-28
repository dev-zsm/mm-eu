#include "types.h"

extern u8 D_8087A040[];

void func_8000120C(u8 *a0) {
    *(s16 *)(a0 + 0x190) = 1;
    *(u8 **)(a0 + 0x188) = D_8087A040;
    *(f32 *)(a0 + 0x70) = 0.0f;
}
