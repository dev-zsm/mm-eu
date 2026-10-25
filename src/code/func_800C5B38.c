#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 lookup[8];
    u16 vtxStartIndex;
    u16 waterBoxStartIndex;
    u8 transform0[0x20];
    u8 transform1[0x20];
    s16 unk54;
    s16 unk56;
    s16 unk58;
    s16 unk5A;
} BgActor;

extern void ScaleRotPos_Init(void *arg0);
extern void DynaLookup_Reset(void *arg0);
extern void DynaLookup_ResetVtxStartIndex(u16 *arg0);
extern void DynaLookup_ResetWaterBoxStartIndex(u16 *arg0);

void BgActor_Init(s32 arg0, BgActor *bgActor) {
    bgActor->unk0 = 0;
    bgActor->unk4 = 0;
    ScaleRotPos_Init(bgActor->transform0);
    ScaleRotPos_Init(bgActor->transform1);
    DynaLookup_Reset(bgActor->lookup);
    DynaLookup_ResetVtxStartIndex(&bgActor->vtxStartIndex);
    DynaLookup_ResetWaterBoxStartIndex(&bgActor->waterBoxStartIndex);
    bgActor->unk58 = 0;
    bgActor->unk5A = 0;
    bgActor->unk54 = bgActor->unk56 = bgActor->unk58;
}
