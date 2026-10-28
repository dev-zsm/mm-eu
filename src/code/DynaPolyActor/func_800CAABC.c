// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x154];
    s32 flags154;
} Dyna;

typedef struct {
    u8 pad0[0x13DC];
    u16 flags13DC[1];
} Ctx;

extern s32 DynaPoly_IsBgIdBgActor(s32 a);
extern Dyna *DynaPoly_GetActor(Ctx *a, s32 b);
extern void DynaPolyActor_UpdateCarriedActorPos(Ctx *a, s32 b, s32 c);
extern void DynaPolyActor_UpdateCarriedActorRotY(Ctx *a, s32 b, s32 c);

s32 DynaPolyActor_TransformCarriedActor(Ctx *ctx, s32 id, s32 actor) {
    s32 ret = 0;
    Dyna *dyna;
    u16 f;

    if (DynaPoly_IsBgIdBgActor(id) == 0) {
        return 0;
    }
    f = ctx->flags13DC[id];
    if ((f & 2) || !(f & 1)) {
        return 0;
    }
    dyna = DynaPoly_GetActor(ctx, id);
    if (dyna == NULL) {
        return 0;
    }
    if (dyna->flags154 & 1) {
        DynaPolyActor_UpdateCarriedActorPos(ctx, id, actor);
        ret = 1;
    }
    if (dyna->flags154 & 2) {
        DynaPolyActor_UpdateCarriedActorRotY(ctx, id, actor);
        ret = 1;
    }
    return ret;
}
