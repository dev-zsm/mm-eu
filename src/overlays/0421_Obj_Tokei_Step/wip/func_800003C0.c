#include "types.h"
typedef struct { s16 v; u8 pad[0x12]; } E;
typedef struct { u8 pad[0x170]; E e[7]; } A;
void ObjTokeiStep_InitTimers(A *a) {
    s32 i = 3;
    a->e[0].v = 0;
    a->e[1].v = 10;
    a->e[2].v = 10;
    a->e[i + 1].v = 10;
    a->e[i + 2].v = 10;
    a->e[i + 3].v = 10;
    a->e[i].v = 10;
}
