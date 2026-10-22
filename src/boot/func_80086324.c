// FLAGS: -O2 -g0
#include "types.h"

extern void Fault_AddHungupAndCrash(void *a0, s32 a1);
extern u8 D_80099340[];

void Reset(void) {
    Fault_AddHungupAndCrash(D_80099340, 0);
}
