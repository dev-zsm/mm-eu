// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

// Defined here, as in the original timer source file: IDO only emits the 64-bit store of
// D_8009E980 as "lui; li; li; sw lo; sw hi" when the variable is defined in the same translation unit.
OSTime D_8009E980;
u32 D_8009E988;
u32 D_8009E98C;

void __osTimerServicesInit(void) {
    D_8009E980 = 0;
    D_8009E988 = 0;
    D_8009E98C = 0;
    D_80098160->prev = D_80098160;
    D_80098160->next = D_80098160->prev;
    D_80098160->value = 0;
    D_80098160->interval = D_80098160->value;
    D_80098160->mq = NULL;
    D_80098160->msg = NULL;
}
