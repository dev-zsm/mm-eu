// FLAGS: -O2 -g0 -mips2 -trapuv
#include "types.h"

extern void Fault_WaitForInputImpl(void);

void Fault_WaitForInput(void) {
    Fault_WaitForInputImpl();
}
