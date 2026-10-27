// FLAGS: -O1 -g0 -mips2 -trapuv
#include "types.h"

extern void func_800819E0(void);

void Fault_Sleep(void) {
    func_800819E0();
}
