// FLAGS: -O2 -g0 -mips2 -trapuv
#include "types.h"

extern void func_80081F50(void);

void func_8008209C(void) {
    func_80081F50();
}
