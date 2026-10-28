#include "types.h"
typedef struct { u8 pad0[0x92]; s16 u92; } A;
typedef struct { u8 pad0[0xB80]; f32 f; s16 s; } B;
void func_800000B0(A *a, B *b) {
    b->f = 30.0f;
    b->s = a->u92;
}
