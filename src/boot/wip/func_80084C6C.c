// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80080CE0(void *p);
void func_800897D0(void *p, s32 n);
void func_80084A00(void *base, void *s, s32 a2);
void func_8008A780(void *p, s32 v);
void func_8008F410(void *p, s32 v);

// best attempt: ROM keeps a3/size in stack slots and uses no s-registers; ours uses s0/s1
s32 func_80084C6C(s32 a0, s32 a1, s32 a2, void *a3, s32 a4) {
    s32 size;
    s32 v1;
    u8 *t0;
    u8 *s;

    size = a1 - a0;
    func_80080CE0(a3);
    t0 = (u8 *)a3 + size;
    s = t0 - *(s32 *)(t0 - 4);
    v1 = *(s32 *)(s + 0xC) + size;
    if (a4 < v1) {
        return 0;
    }
    a4 = v1;
    func_80084A00(a3, s, a2);
    if (*(s32 *)(s + 0xC) != 0) {
        func_800897D0(t0, *(s32 *)(s + 0xC));
    }
    func_800897D0(s, *(s32 *)(s + 0x10) * 4 + 0x14);
    func_8008A780(a3, a4);
    func_8008F410(a3, a4);
    return a4;
}
