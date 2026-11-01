// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct {
    u8 b;
    u8 pad[0x2B];
} E;

void func_80000000(E *p) {
    register s32 i = 0;
    do {
        i += 4;
        p[1].b = 0;
        p[2].b = 0;
        p[3].b = 0;
        p += 4;
        p[-4].b = 0;
    } while (i != 0x190);
}
