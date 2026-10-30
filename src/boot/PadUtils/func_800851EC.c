// FLAGS: -O2 -g0
#include "padutils.h"

s32 PadUtils_CheckCur(Input *input, u16 key) {
    return ((input->cur.button & key) ^ key) == 0;
}
