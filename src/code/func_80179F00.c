#include "types.h"
void func_800807E0(s32, void *, s32);
extern s32 D_801F3460[];

void func_80179F00(s32 arg0, u32 arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    s32 v1;
    u32 v0;

    func_800807E0(arg0, D_801F3460, 4);
    v1 = D_801F3460[0];
    v0 = arg1 * 4;
    if ((u32)(v1 - 4) < v0) {
        *arg2 = arg0;
        *arg3 = 0;
    } else if (v0 == 0) {
        func_800807E0(arg0 + 4, D_801F3460, 4);
        *arg2 = arg0 + v1;
        *arg3 = D_801F3460[0];
    } else {
        func_800807E0((s32)v0 + arg0, D_801F3460, 8);
        *arg2 = D_801F3460[0] + arg0 + v1;
        *arg3 = D_801F3460[1] - D_801F3460[0];
    }
    *arg4 = 0;
}
