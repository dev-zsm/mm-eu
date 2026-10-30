// FLAGS: -O2 -g0 -mips2
#include "padutils.h"

void PadUtils_SetRelXY(Input *input, s32 x, s32 y) {
    input->rel.stick_x = x;
    input->rel.stick_y = y;
}
