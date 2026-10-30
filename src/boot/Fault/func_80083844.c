// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_UpdatePad(void) {
    Fault_UpdatePadImpl();
    Fault_SetOptions();
}
