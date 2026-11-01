#include "types.h"
typedef struct { u16 id; u16 pad; s32 v; } Ent;
typedef struct { u8 pad0[0x11D80]; s32 d0; s32 d1; } Sub;
typedef struct { u8 pad0[0x4A70]; Sub sub; u8 pad1[0x16990 - 0x4A70 - sizeof(Sub)]; Ent *tbl; } Ctx;
void func_80159010(Ctx *c, u16 id) {
    Ent *p = c->tbl;
    s32 start = p->v;
    Sub *s = &c->sub;
    while (p->id != 0xFFFF) {
        if (id == p->id) {
            s->d0 = p[0].v - start;
            s->d1 = p[1].v - p[0].v;
            p++;
            return;
        }
        p++;
    }
    p = c->tbl;
    s->d0 = p->v - start;
    s->d1 = p[1].v - p->v;
    p++;
}
