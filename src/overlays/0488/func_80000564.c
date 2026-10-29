#include "types.h"

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
} S;

typedef struct {
    u32 w;
    u8 pad[0x18];
} E;

extern E D_801E6FFC[];

s32 func_80000564(S *s) {
    return D_801E6FFC[s->unkA4].w & 1;
}
