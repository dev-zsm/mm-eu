#include "types.h"

typedef struct {
    s32 flags;
    u8 pad[24];
} Entry;

extern Entry D_801E6FFC[];

typedef struct {
    u8 pad[0xA4];
    s16 idx;
} Actor;

s32 func_80000134(Actor *a) {
    return D_801E6FFC[a->idx].flags & 1;
}
