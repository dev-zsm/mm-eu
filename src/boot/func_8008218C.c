// FLAGS: -O2 -g0 -mips2 -trapuv
#include "types.h"

extern void func_8008431C(s32 a);
extern void func_80084368(s32 a);
extern void func_80084538(void);

void func_8008218C(void) {
    func_8008431C(0xFFFF);
    func_80084368(0xF001);
    func_80084538();
    func_80084368(0);
}
