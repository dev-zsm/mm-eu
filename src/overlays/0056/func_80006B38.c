#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 a;
    u8 pad1[0x20 - 5];
    u8 b;
    u8 pad2[0x70 - 0x21];
    u8 c[1];
} G;

extern u8 D_801C2D6A;
extern G D_801E6EF0;

void func_80006B38(void) {
    if (D_801E6EF0.c[D_801C2D6A] == 0x32) {
        D_801E6EF0.b = 4;
        D_801E6EF0.a = 0;
    }
}
