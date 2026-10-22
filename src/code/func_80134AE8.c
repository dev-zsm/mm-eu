// FLAGS: -O2 -g3 -mips2
#include "types.h"

u16 *func_80100304();                               /* extern */

s16 Animation_GetLastFrame(void) {
    return (s16) (*func_80100304() - 1);
}
