#include "types.h"

typedef struct { u8 pad[0x40]; s16 a; s16 b; s16 c; } S0206;

void func_80000180(s32 a0, s32 a1, S0206 *a2) {
    a2->a = a2->a + a2->c;
}
