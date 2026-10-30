// FLAGS: -O2 -g0 -mips2
#include "types.h"
u8 *func_8000030C(u8 *a) {
    u8 *p;
    p = *(u8 **)(a + 0x1CE4);
    if (p != 0) {
        do {
            if (*(s16 *)p == 0x1FF) {
                return p;
            }
            p = *(u8 **)(p + 0x12C);
        } while (p != 0);
    }
    return 0;
}
