#include "types.h"

typedef struct {
    u8 pad[0x158];
    u8 f158;
    u8 pad2[6];
    s32 f160;
    u8 pad3[1];
    u8 f165;
} A;

void func_800000FC(A *a) {
    a->f158 &= 0xFFE9;
    a->f158 |= 8;
    a->f160 = 0x400000;
    a->f165 = 2;
}
