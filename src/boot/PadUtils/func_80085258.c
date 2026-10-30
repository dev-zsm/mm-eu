// FLAGS: -O2 -g0 -mips2
#include "padutils.h"

s8 PadUtils_GetCurY(Input *input) {
    return input->cur.stick_y;
}
