#include "types.h"

typedef struct {
    u8 pad0[0x14B];
    u8 b;
} T;

extern void func_8082D270();
extern s32 D_8085C86C[];

void func_8002C8E4(s32 a, T *b, s32 c) {
    func_8082D270(a, b, D_8085C86C[b->b]);
}
