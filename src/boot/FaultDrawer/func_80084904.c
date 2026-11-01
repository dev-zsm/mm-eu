// FLAGS: -O2 -g3 -mips2
#include "boot/faultdrawer.h"

void FaultDrawer_SetInputCallback(FaultDrawerCallback callback) {
    D_80096D80->inputCallback = callback;
}
