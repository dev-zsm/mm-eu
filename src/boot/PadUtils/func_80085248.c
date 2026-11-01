// FLAGS: -O2 -g0 -mips2
#include "boot/padutils.h"

u16 PadUtils_GetPressButton(Input *input) {
    return input->press.button;
}
