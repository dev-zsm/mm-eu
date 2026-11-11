// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0293.h"

void func_80115540();
void func_809F15DC();
void func_809F1FE8();
extern u8 D_809F24AC;

void func_80000A48(s32 arg0, s32 arg1, u8 arg2) {
    func_80115540(arg0, 0x10);
    if (arg2 == 0) {
        func_809F15DC(arg1, &D_809F24AC);
        return;
    }
    func_809F1FE8(arg0, arg1);
}
