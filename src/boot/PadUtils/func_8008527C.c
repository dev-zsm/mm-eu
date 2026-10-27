// FLAGS: -O2 -g0 -mips2
#include "types.h"

void PadUtils_GetRelXImpl(void);

void PadUtils_GetRelX(void) {
    PadUtils_GetRelXImpl();
}
