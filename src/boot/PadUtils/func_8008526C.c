// FLAGS: -O2 -g0 -mips2
#include "padutils.h"

s8 PadUtils_GetRelXImpl(Input *input) {
    return input->rel.stick_x;
}
