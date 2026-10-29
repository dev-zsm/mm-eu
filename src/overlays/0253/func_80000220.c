#include "types.h"

typedef struct {
    s16 pad;
    s16 pad2;
    s16 v;
} E;

typedef struct {
    u8 pad[0x1C];
    u16 f1C;
} A;

void func_80000220(A *a, u8 *b) {
    s32 i = a->f1C >> 10;
    E *e = (E *)(*(u8 **)(b + 0x20000 - 0x789C) + i * 16);
    e->v = -e->v;
}
