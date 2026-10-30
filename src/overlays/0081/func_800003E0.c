#include "types.h"
typedef struct { u8 pad0[3]; s8 b3; u8 pad1[0x1C-4]; u16 h1C; } A;
typedef struct { s16 a, b, c, d; s32 e, f; } Q;
typedef struct { u8 pad[0x18764]; Q *p; } B;
void func_800003E0(A *a, B *b) {
    s32 i;
    Q *q;
    if (a->b3 >= 0) {
        i = a->h1C;
        i >>= 10;
        q = b->p + i;
        q->c = -q->c;
    }
}
