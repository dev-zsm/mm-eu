#include "types.h"
typedef struct { u8 pad[0x14C]; s16 unk14C; } Act;
typedef struct {
    u8 pad0[0x800];
    Act *arr[4];
    s16 idx;
    u8 pad812[0x170F6 - 0x812];
    u8 b170F6;
    u8 pad170F7;
    u8 b170F8;
    u8 pad170F9;
    u8 b170FA;
} Ctx;
s32 Environment_GetStormState(Ctx *);
u8 func_800FE7AC(Ctx *c) {
    u8 r = 0;
    if (c->b170FA == 0x3C && c->b170F8 == 0) {
        r = 1;
    }
    if (c->b170F6 == 0x3C && !(c->arr[c->idx]->unk14C & 0x100)) {
        if (Environment_GetStormState(c) != 0 && c->b170F8 == 0) {
            r = 1;
        }
    }
    return r;
}
