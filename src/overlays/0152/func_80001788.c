// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad[0x194]; u8 t; } S;
extern void func_8091AD80();

void func_80001788(S *s, s32 a1) {
    s->t++;
    if (s->t >= 0x78) {
        func_8091AD80();
    }
}
