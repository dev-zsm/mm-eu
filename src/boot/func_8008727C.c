// FLAGS: -O2 -g0
#include "types.h"
typedef struct Pool {
    void *head;
    u32 start;
    u8 pad8[0x19];
    u8 unk21;
} Pool;
void func_800897D0(void *a, u32 b);
void func_800871D0(void *p);
void func_800872CC(void *p, u32 a, s32 b);
void func_8008727C(Pool *arg0, u32 arg1, s32 arg2) {
    func_800897D0(arg0, 0x24);
    func_800871D0(arg0);
    func_800872CC(arg0, arg1, arg2);
    arg0->unk21 = 1;
}
