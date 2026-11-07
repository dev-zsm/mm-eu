// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
typedef struct { u8 pad0[0x24]; f32 x; u8 pad1[0x4]; f32 z; u8 pad2[0x208]; f32 r; } A;
typedef struct { f32 x; u8 pad0[0x4]; f32 z; } V;
s32 func_80000414(A *a, V *b) {
    f32 dx = a->x - b->x;
    f32 dz = a->z - b->z;
    if (a->r <= dx * dx + dz * dz) {
        return 1;
    }
    return 0;
}
