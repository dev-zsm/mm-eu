#include "types.h"
typedef struct { u8 p0[0x1C]; s16 u1C; u8 p1[0x2EE]; u16 u30C; } A;
extern u16 D_809008A8[];
void func_80000000(A *a) {
    a->u30C = D_809008A8[a->u1C & 1];
}
