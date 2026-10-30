// FLAGS: -O2 -g0 -mips2 -trapuv
#include "fault.h"

void Fault_WaitForInput(void) {
    Fault_WaitForInputImpl();
}
