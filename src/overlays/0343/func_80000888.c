#include "types.h"

typedef struct {
    u8 pad[0x260];
    s32 v[1];
} B;

s32 func_80000888(s32 a, s32 i, s32 *p, s32 d, s32 e, B *b) {
    b->v[i] = *p;
    *p = 0;
    return 0;
}
