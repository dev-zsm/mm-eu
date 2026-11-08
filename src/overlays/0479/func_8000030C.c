// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/overlays/0479.h"
u8 * func_8000030C(PlayState *play) {
    u8 *p;
    p = *(u8 **)((u8 *)play + 0x1CE4);
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
