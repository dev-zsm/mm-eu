#include "types.h"

extern u8 D_808E9F20;

void func_80001578(u8 *a0) {
    u8 *v;

    if (*(u8 **)(a0 + 0x188) == &D_808E9F20) {
        v = *(u8 **)(a0 + 0xA44);
        if (*(s16 *)(v + 0x1C) == 0xA) {
            *(s16 *)(v + 0x1C) = 3;
        }
    }
}
