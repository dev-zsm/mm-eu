// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098020;
extern u8 D_8009D280[];
extern u8 D_8009D288[];
void func_8008F3E0(void *a, void *b, s32 c);
void func_80087CB0(void *a, s32 b, s32 c);

void func_80089C40(void) {
    D_80098020 = 1;
    func_8008F3E0(D_8009D288, D_8009D280, 1);
    func_80087CB0(D_8009D288, 0, 0);
}
