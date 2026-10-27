// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

void Fault_UpdatePadImpl(void);
void Fault_SetOptions(void);

void Fault_UpdatePad(void) {
    Fault_UpdatePadImpl();
    Fault_SetOptions();
}
