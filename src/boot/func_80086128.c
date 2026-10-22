// FLAGS: -O2 -g3 -mips2
#include "types.h"

void vaprintf(void);

void GfxPrint_VPrintf(void) {
    vaprintf();
}
