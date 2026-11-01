// FLAGS: -O2 -g0 -mips2
#include "boot/padutils.h"

s8 PadUtils_GetRelY(Input *input) {
    return PadUtils_GetRelYImpl(input);
}
