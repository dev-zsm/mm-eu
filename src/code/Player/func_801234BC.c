#include "types.h"
typedef struct { u8 pad[0x1CCC]; u8 *p; } S1;
void func_801234BC(S1 *a, s32 b) { u8 *q = a->p; q[0xB2B] = b; }
