// FLAGS: -O2 -g3 -mips2
#include "faultdrawer.h"

void FaultDrawer_SetOsSyncPrintfEnabled(s32 enabled) {
    D_80096D80->osSyncPrintfEnabled = enabled;
}
