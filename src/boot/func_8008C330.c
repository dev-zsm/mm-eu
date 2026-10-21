// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098090;
extern u8 D_8009E7C8[];
extern u8 D_8009E7C0[];
extern void func_8008F3E0(void *a, void *b, s32 c);
extern void func_80087CB0(void *a, s32 b, s32 c);

void func_8008C330(void) {
    D_80098090 = 1;
    func_8008F3E0(D_8009E7C8, D_8009E7C0, 1);
    func_80087CB0(D_8009E7C8, 0, 0);
}
