// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void *func_80080944(void);
extern u8 D_8009FC80[];

s32 func_80080A0C(void) {
    u8 *p = func_80080944();

    if (p != 0) {
        return (p - D_8009FC80) >> 4;
    }
    return -1;
}
