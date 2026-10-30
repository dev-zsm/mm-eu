#include "types.h"

typedef struct { u8 p0[0x2448C]; s16 u2448C; } A;
extern void (*D_808163E8[])();

void func_80010404(A *a) {
    D_808163E8[a->u2448C]();
}
