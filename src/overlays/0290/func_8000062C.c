// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
typedef struct { u8 pad0[0x24]; f32 x; u8 pad1[0x4]; f32 z; } Q;
typedef struct { u8 pad0[0x1CCC]; Q* q; } P;
void func_8000062C(P *play) {
    Q *pl = play->q;
    f32 x = pl->x;
    f32 z = pl->z;
    if (x * x + z * z < 6400.0f) {
        pl->z = 90.0f;
    }
}
