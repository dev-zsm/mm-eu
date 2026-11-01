// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 THA_GetRemaining();                                /* extern */

s32 THA_IsCrash(void) {
    return THA_GetRemaining() < 0;
}
