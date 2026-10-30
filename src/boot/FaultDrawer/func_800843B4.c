// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"

void FaultDrawer_SetFontColor(u16 color) {
    FaultDrawer_SetForeColor(color | 1);
}
