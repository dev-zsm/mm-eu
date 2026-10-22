// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void func_8008F3E0(void *a, void *b, u32 c);
extern void func_800942F0(void *p, u64 x, u32 e5, u32 e6, void *e7, u32 e8);
extern void func_80088070(void *a, u32 b, u32 c);
void func_80087B00(u64 x) {
    u8 e[0x14]; u32 sp50; u32 sp4C; u8 pad28[0x24];
    func_8008F3E0(&sp50, &sp4C, 1);
    func_800942F0(pad28, x, 0, 0, &sp50, 0);
    func_80088070(&sp50, 0, 1);
}
