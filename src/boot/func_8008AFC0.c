// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 func_80091C00(void);
extern void func_80091C70(s32 a0, void *a1);
extern u8 D_8009807C[];

s32 func_8008AFC0(void *arg0) {
    s32 temp_a0;

    temp_a0 = func_80091C00();
    *(void **)arg0 = *(void **)&D_8009807C;
    *(void **)&D_8009807C = arg0;
    func_80091C70(temp_a0, arg0);
    return 0;
}
