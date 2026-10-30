// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { u8 p[0x1C]; s16 u1C; } A;
extern void func_800B6564();
extern s32 D_809FE600[];

void func_80000000(A *a, s32 b) {
    func_800B6564(a, D_809FE600[a->u1C & 1]);
}
