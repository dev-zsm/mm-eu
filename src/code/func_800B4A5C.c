#include "types.h"

typedef struct {
    u8 pad0[0x24];
    f32 unk24;
    f32 unk28;
    u8 pad2C[0x54];
    u8 unk80[5];
    u8 unk85;
    u8 pad86[2];
    f32 unk88;
} BgActor;

extern f32 BgCheck_EntityRaycastFloor5_2(void *play, void *colCtx, void *poly, s32 *bgId, BgActor *actor, void *pos);

void func_800B4A5C(void *play, BgActor *actor, f32 yOffset) {
    s32 bgId;
    f32 prevY;

    prevY = actor->unk28;
    actor->unk28 += yOffset;
    actor->unk88 = BgCheck_EntityRaycastFloor5_2(play, (u8 *)play + 0x830, actor->unk80, &bgId, actor, &actor->unk24);
    actor->unk85 = bgId;
    actor->unk28 = prevY;
}
