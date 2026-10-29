#include "types.h"

typedef struct {
    u8 pad0[0x2BA];
    s8 b;
    u8 pad1[0x3A8 - 0x2BB];
    s32 c;
} T;

s32 func_80002F60(s32 a, s32 b, s32 *c, s32 d, s32 f, T *e) {
    if (e->b == -1) {
        e->c = *c;
        *c = 0;
    }
    return 0;
}
