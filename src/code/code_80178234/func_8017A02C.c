#include "types.h"

extern void func_80179F00(s32, s32, s32 *, s32 *, s32 *);
extern s32 func_80086E40(s32);
extern void func_80086EC0(s32);
extern void func_80179D40(s32, s32, s32);
extern void func_80179FFC(s32, s32, s32);

void func_8017A02C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    func_80179F00(arg0, arg1, &sp2C, &sp28, &sp24);
    if (sp24 & 1) {
        sp20 = func_80086E40(0x1000);
        func_80179FFC(sp2C, sp28, sp20);
        func_80179D40(sp20, arg2, arg3);
        func_80086EC0(sp20);
        return;
    }
    func_80179FFC(sp2C, sp28, arg2);
}
