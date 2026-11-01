#include "types.h"

typedef struct {
    u8 pad0[0x116];
    s16 unk116;
    u8 pad118[0x374];
    s32 unk48C;
} Ovl0127Actor;

typedef struct {
    u8 pad0[0xF54];
    u8 unkF54;
} Ovl0127Glob;

extern Ovl0127Glob D_801E6EF0;

s32 func_80001330(Ovl0127Actor *a) {
    Ovl0127Glob *g = &D_801E6EF0;
    s32 v;
    s32 w;
    a->unk48C = 0;
    a->unk116 = 0;
    v = g->unkF54 & 0xF8;
    w = (v & 0xFFF8) | v;
    g->unkF54 = v;
    g->unkF54 = w;
    return 0;
}
