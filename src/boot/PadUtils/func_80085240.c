// FLAGS: -O2 -g0 -mips2
#include "boot/padutils.h"

u16 PadUtils_GetCurButton(Input *input) {
    return input->cur.button;
}
