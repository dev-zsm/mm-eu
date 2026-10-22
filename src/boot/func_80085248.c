// FLAGS: -O2 -g0 -mips2
#include "types.h"

u16 PadUtils_GetPressButton(u8 *a0) {
    return *(u16 *)(a0 + 0xC);
}
