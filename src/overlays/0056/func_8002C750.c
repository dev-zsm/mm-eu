#include "types.h"

typedef struct {
    u8 pad0[0xAAA];
    s16 unkAAA;
} Ovl0056Ctx;

extern void func_8082D1C8();
extern u8 D_400D2D0[];

void func_8002C750(s32 a, Ovl0056Ctx *b, s32 c) {
    func_8082D1C8(a, b, D_400D2D0);
    b->unkAAA = -0x8000;
}
