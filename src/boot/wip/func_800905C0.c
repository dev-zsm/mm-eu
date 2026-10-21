// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void func_80091C00(void);
extern s32 func_8008D460(void);
extern void func_80091C70(s32 a0);
extern u32 D_8009E980;
extern u32 D_8009E984;
extern u32 D_8009E988;

u32 func_800905C0(void) {
    s32 temp_s0;
    s32 sp34;
    u32 sp30;
    u32 sp2C;
    u32 sp28;
    func_80091C00();
    temp_s0 = func_8008D460();
    sp34 = temp_s0;
    sp30 = sp34 - D_8009E988;
    sp2C = D_8009E984;
    sp28 = D_8009E980;
    func_80091C70(temp_s0);
    return sp28 + ((sp30 + sp2C) < sp2C);
}
