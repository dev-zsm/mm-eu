#include "types.h"
extern u8 D_80A94624[];
typedef struct { u8 pad0[0x1A0]; u8 *p; } A;
typedef struct { u8 pad0[0x1F2C]; u8 u; } B;
void func_80000A74(A *a, B *b) {
    if (b->u == 0) { a->p = D_80A94624; }
}
