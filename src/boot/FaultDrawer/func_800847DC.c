// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"

void FaultDrawer_VPrintf(const char *fmt, va_list args) {
    _Printf(FaultDrawer_FormatStringFunc, D_80096D80, fmt, args);
}
