// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad[0x3D0]; s16 t; } S;
extern void func_800B6490();

void func_80001CF0(S *s, s32 a1) {
    if (s->t++ >= 0x13) {
        func_800B6490();
    }
}
