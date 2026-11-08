// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad[0x24486];
    s16 a;
    u8 pad2[0x2450C - 0x24488];
    f32 f;
} T0053;

void func_8000A6DC(T0053 *arg0) {
    arg0->f += 50.0f;
    if (arg0->f >= 314.0f) {
        arg0->f = 314.0f;
        arg0->a = 0x28;
    }
}
