// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

void func_80081F04(void);
void func_800836D0(void);

void func_80083844(void) {
    func_80081F04();
    func_800836D0();
}
