#include "types.h"

typedef struct {
    u8 pad0[4];
    u32 flags;
} Actor;

extern s32 DynaPoly_IsBgIdBgActor(s32 a);
extern s32 DynaPoly_GetActor(s32 a, s32 b);
extern void DynaPolyActor_SetActorOnTop(s32 a);
extern void DynaPolyActor_SetSwitchPressed(s32 a);
extern void DynaPolyActor_SetHeavySwitchPressed(s32 a);

void DynaPolyActor_AttachCarriedActor(s32 a0, Actor* actor, s32 bgId) {
    s32 poly;

    if (DynaPoly_IsBgIdBgActor(bgId) != 0) {
        poly = DynaPoly_GetActor(a0, bgId);
        if (poly != 0) {
            DynaPolyActor_SetActorOnTop(poly);
            if ((actor->flags & 0x04000000) == 0x04000000) {
                DynaPolyActor_SetSwitchPressed(poly);
            }
            if ((actor->flags & 0x20000) == 0x20000) {
                DynaPolyActor_SetHeavySwitchPressed(poly);
            }
        }
    }
}
