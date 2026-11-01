#include "types.h"
typedef struct { u8 pad0[0x98]; f32 f98; f32 f9C; } Ctx;
s32 Actor_HasParent(Ctx *c, s32 a, u8 **p);
void Actor_OfferGetItem(Ctx *c, s32 a, s32 b, f32 x, f32 y);
float fabsf(float);
#pragma intrinsic (fabsf)
s32 MsgEvent_OfferItem(Ctx *c, s32 a, u8 **p, s32 unused) {
    s32 pad;
    s32 t;
    f32 x;
    f32 y;
    s16 n;
    u8 *b = *p;
    s32 ret;
    t = (b[1] << 8) | b[2];
    x = c->f98 + 1.0f;
    y = fabsf(c->f9C) + 1.0f;
    n = (b[3] << 8) | b[4];
    if (Actor_HasParent(c, a, p)) {
        *p += n;
        ret = 0;
    } else {
        Actor_OfferGetItem(c, a, t, x, y);
        ret = 1;
    }
    return ret;
}
