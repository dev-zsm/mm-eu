// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u8 pad[0xA0]; u8 *unkA0; } Info;
typedef struct { Info *info; } Obj;
extern f32 D_801BAD30[];
s32 CollisionCheck_GetElementATDamage(u32 *, Obj *);
f32 CollisionCheck_GetDamageAndEffectOnElementAC(s32 a0, u32 *a1, Obj *a2, s32 a3, s32 *out) {
    f32 f;
    u8 *tbl;
    s32 i;
    u32 v;
    u8 b;
    *out = 0;
    f = CollisionCheck_GetElementATDamage(a1, a2);
    tbl = a2->info->unkA0;
    i = 0;
    if (tbl != 0) {
        v = *a1;
        for (i = 0; i < 0x20; i++) {
            if (v == 1) {
                break;
            }
            v >>= 1;
        }
        b = tbl[i];
        f *= D_801BAD30[b & 0xF];
        *out = (b >> 4) & 0xF;
    }
    return f;
}
