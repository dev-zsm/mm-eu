// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Environment_ZBufValToFixedPoint(s32);                             /* extern */
s32 func_80179CA8();                                /* extern */

s32 func_80179D08(void) {
    return Environment_ZBufValToFixedPoint(func_80179CA8() * 4) >> 3;
}
