// FLAGS: -O2 -g0 -mips2
#include "padutils.h"

s32 PadUtils_CheckReleased(Input *input, u16 key) {
    return ((input->rel.button & key) ^ key) == 0;
}
