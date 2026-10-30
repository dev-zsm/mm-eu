// FLAGS: -O2 -g0 -mips2
#include "stackcheck.h"

s32 StackCheck_Check(StackEntry *entry) {
    if (entry == NULL) {
        return StackCheck_CheckAll();
    }
    return StackCheck_GetState(entry);
}
