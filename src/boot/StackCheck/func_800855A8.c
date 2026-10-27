// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void StackCheck_GetState(void);
extern void StackCheck_CheckAll(void);

void StackCheck_Check(s32 arg0) {
    if (arg0 == 0) {
        StackCheck_CheckAll();
    } else {
        StackCheck_GetState();
    }
}

