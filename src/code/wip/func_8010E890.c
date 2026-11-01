#include "types.h"
extern s16 D_801C0430;
extern u8 D_801E6EF0[];
void func_8010E890(s16 a0, s16 a1) {
    s64 t;
    *(s16 *)(D_801E6EF0 + a0 * 2 + 0x3EF8) = 0x73;
    *(s16 *)(D_801E6EF0 + a0 * 2 + 0x3F06) = 0x50;
    t = a1 * 100;
    D_801C0430 = 0;
    *(s64 *)(D_801E6EF0 + a0 * 8 + 0x3DE0) = t;
    *(s64 *)(D_801E6EF0 + a0 * 8 + 0x3E18) = t;
    if (t != 0) {
        D_801E6EF0[a0 + 0x3DD7] = 0;
    } else {
        D_801E6EF0[a0 + 0x3DD7] = 1;
    }
    D_801E6EF0[a0 + 0x3DD0] = 1;
}
