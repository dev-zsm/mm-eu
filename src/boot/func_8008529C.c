// FLAGS: -O2 -g0 -mips2
#include "types.h"

void PadUtils_GetRelYImpl(void);

void PadUtils_GetRelY(void) {
    PadUtils_GetRelYImpl();
}
