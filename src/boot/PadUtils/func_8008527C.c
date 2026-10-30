// FLAGS: -O2 -g0 -mips2
#include "padutils.h"

s8 PadUtils_GetRelX(Input *input) {
    return PadUtils_GetRelXImpl(input);
}
