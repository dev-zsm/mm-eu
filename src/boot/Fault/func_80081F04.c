// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_UpdatePadImpl(void) {
    D_8009C220->padCallback(D_8009C220->padInput);
}
