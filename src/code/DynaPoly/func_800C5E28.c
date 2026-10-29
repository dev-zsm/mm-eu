#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 bg[50][0x64];
    u16 flags[50];
    u8 poly[4];
    u8 vtx[4];
    u8 water[8];
    u8 ss[0xC];
    s32 ssMax;
    s32 polyMax;
    s32 vtxMax;
} Mgr;

extern void BgActor_Init();
extern void DynaPoly_NullPolyList();
extern void DynaPoly_AllocPolyList();
extern void DynaPoly_NullVtxList();
extern void DynaPoly_AllocVtxList();
extern void DynaPoly_InitWaterBoxList();
extern void DynaPoly_AllocWaterBoxList();
extern void DynaSSNodeList_Init();
extern void DynaSSNodeList_Alloc();

void DynaPoly_Alloc(s32 play, Mgr *mgr) {
    s32 i;

    for (i = 0; i < 50; i++) {
        BgActor_Init(play, mgr->bg[i]);
        mgr->flags[i] = 0;
    }
    DynaPoly_NullPolyList(mgr->poly);
    DynaPoly_AllocPolyList(play, mgr->poly, mgr->polyMax);
    DynaPoly_NullVtxList(mgr->vtx);
    DynaPoly_AllocVtxList(play, mgr->vtx, mgr->vtxMax);
    DynaPoly_InitWaterBoxList(mgr->water);
    DynaPoly_AllocWaterBoxList(play, mgr->water, 0x1E);
    DynaSSNodeList_Init(play, mgr->ss);
    DynaSSNodeList_Alloc(play, mgr->ss, mgr->ssMax);
}
