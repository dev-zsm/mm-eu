// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { u8 pad[0x1A0]; void *p1A0; } S0387;
typedef struct { u8 pad[0x1F2C]; u8 b1F2C; } G0387;
extern u8 D_80A94834[];

void func_80000A94(S0387 *a0, G0387 *a1) {
    if (a1->b1F2C == 0) {
        a0->p1A0 = D_80A94834;
    }
}
