#include "types.h"

extern s32 D_8085BAD4;
extern void func_8013698C();

void func_8000120C(s32 a, u8 *b, s32 c) {
    func_8013698C(a, b + 0x240, c, D_8085BAD4);
}
