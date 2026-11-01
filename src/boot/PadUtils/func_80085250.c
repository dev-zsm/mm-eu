// FLAGS: -O2 -g0 -mips2
#include "boot/padutils.h"

s8 PadUtils_GetCurX(Input *input) {
    return input->cur.stick_x;
}
