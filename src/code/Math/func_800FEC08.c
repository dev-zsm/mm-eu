// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Math_StepToIImpl(s32);                             /* extern */

void Math_StepToIGet(s32 *arg0) {
    *arg0 = Math_StepToIImpl(*arg0);
}
