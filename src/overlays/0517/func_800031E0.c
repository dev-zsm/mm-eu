#include "types.h"
extern void func_80B6AB38();
extern u8 D_80B6D4CC[];
typedef struct { u8 pad0[0x2AC]; void *fn; s16 t; } A;
void func_800031E0(A *a) {
    func_80B6AB38(a, 3);
    a->t = 10;
    a->fn = D_80B6D4CC;
}
