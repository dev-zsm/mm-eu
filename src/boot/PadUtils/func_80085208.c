// FLAGS: -O2 -g0 -mips2
#include "padutils.h"

s32 PadUtils_CheckPressed(Input *input, u16 key) {
    return ((input->press.button & key) ^ key) == 0;
}
