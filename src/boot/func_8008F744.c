// FLAGS: -O1 -g0 -mips2
#include "types.h"

extern u32 D_8009E990;
extern void *func_80091C00(void);
extern u32 func_8008D460(void);
extern void func_80091420(u32 a);
extern void func_80091C70(void *a);

void func_8008F744(u64 v) {
    u64 sum;
    void *s;

    if (v < 0x1D4) {
        v = 0x1D4;
    }
    s = func_80091C00();
    D_8009E990 = func_8008D460();
    sum = v + D_8009E990;
    func_80091420((u32)sum);
    func_80091C70(s);
}
