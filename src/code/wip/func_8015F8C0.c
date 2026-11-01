#include "types.h"

typedef struct { u16 id; u8 b; u8 pad; s32 off; u32 pad8; s32 next; } Ent;
typedef struct {
    u8 slot0;
    u8 pad1[0x11D80 - 1];
    s32 a;
    s32 b;
    u8 idx;
    u8 pad2[0x11F28 - 0x11D89];
    Ent *tbl;
} Sub;
typedef struct { u8 pad0[0x4A70]; Sub sub; } Ctx;

void func_8015F8C0(Ctx *ctx, u16 id) {
    Ent *e = ctx->sub.tbl;
    s32 first = e->off;
    Sub *s;

    while (e->id != 0xFFFF) {
        if (id == e->id) {
            s = &ctx->sub;
            *((u8 *)s + s->idx * 0x3C00) = e->b;
            s->a = e->off - first;
            s->b = e->next - e->off;
            return;
        }
        e = (Ent *)((u8 *)e + 8);
    }
}
