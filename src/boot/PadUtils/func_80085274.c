// FLAGS: -O2 -g0 -mips2
#include "padutils.h"

s8 PadUtils_GetRelYImpl(Input *input) {
    return input->rel.stick_y;
}
