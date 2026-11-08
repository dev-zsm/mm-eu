// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80115540();
void func_808A77C0();
void func_808A7E28();
extern u8 D_808A860C;

void func_80000608(s32 arg0, s32 arg1, u8 arg2) {
    func_80115540(arg0, 0x10);
    if (arg2 == 0) {
        func_808A77C0(arg1, &D_808A860C);
        return;
    }
    func_808A7E28(arg0, arg1);
}
