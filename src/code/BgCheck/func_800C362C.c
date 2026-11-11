// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

void BgCheck_Allocate(CollisionContext* colCtx, PlayState* play, CollisionHeader* colHeader) {
    u32 tblMax;
    u32 memSize;
    u32 lookupTblMemSize;
    SSNodeList* nodeList;
    s32 customNodeListMax;

    customNodeListMax = -1;
    colCtx->colHeader = colHeader;
    colCtx->flags = 0;

    if (BgCheck_IsSmallMemScene(play)) {
        colCtx->memSize = 0xF000;
        colCtx->dyna.polyNodesMax = 1000;
        colCtx->dyna.polyListMax = 512;
        colCtx->dyna.vtxListMax = 512;
        colCtx->subdivAmount.x = 16;
        colCtx->subdivAmount.y = 4;
        colCtx->subdivAmount.z = 16;
    } else {
        u32 customMemSize;
        s32 useCustomSubdivisions;
        s32 i;

        if (BgCheck_TryGetCustomMemsize(play->sceneId, &customMemSize)) {
            colCtx->memSize = customMemSize;
        } else {
            colCtx->memSize = 0x23000;
        }
        colCtx->dyna.polyNodesMax = 1000;
        colCtx->dyna.polyListMax = 544;
        colCtx->dyna.vtxListMax = 512;
        BgCheck_GetSpecialSceneMaxObjects(play, &colCtx->dyna.polyNodesMax, &colCtx->dyna.polyListMax,
                                          &colCtx->dyna.vtxListMax);
        useCustomSubdivisions = false;

        for (i = 0; i < ARRAY_COUNT(sSceneSubdivisionList); i++) {
            if (play->sceneId == sSceneSubdivisionList[i].sceneId) {
                colCtx->subdivAmount.x = sSceneSubdivisionList[i].subdivAmount.x;
                colCtx->subdivAmount.y = sSceneSubdivisionList[i].subdivAmount.y;
                colCtx->subdivAmount.z = sSceneSubdivisionList[i].subdivAmount.z;
                useCustomSubdivisions = true;
                customNodeListMax = sSceneSubdivisionList[i].nodeListMax;
            }
        }
        if (useCustomSubdivisions == false) {
            colCtx->subdivAmount.x = 16;
            colCtx->subdivAmount.y = 4;
            colCtx->subdivAmount.z = 16;
        }
    }
    colCtx->lookupTbl = THA_AllocTailAlign(
        &play->state.tha,
        colCtx->subdivAmount.x * sizeof(StaticLookup) * colCtx->subdivAmount.y * colCtx->subdivAmount.z, ~1);
    if (colCtx->lookupTbl == NULL) {
        Fault_AddHungupAndCrash("../z_bgcheck.c", LN1(3952, 3955));
    }
    colCtx->minBounds.x = colCtx->colHeader->minBounds.x;
    colCtx->minBounds.y = colCtx->colHeader->minBounds.y;
    colCtx->minBounds.z = colCtx->colHeader->minBounds.z;
    colCtx->maxBounds.x = colCtx->colHeader->maxBounds.x;
    colCtx->maxBounds.y = colCtx->colHeader->maxBounds.y;
    colCtx->maxBounds.z = colCtx->colHeader->maxBounds.z;
    BgCheck_SetSubdivisionDimension(colCtx->minBounds.x, colCtx->subdivAmount.x, &colCtx->maxBounds.x,
                                    &colCtx->subdivLength.x, &colCtx->subdivLengthInv.x);
    BgCheck_SetSubdivisionDimension(colCtx->minBounds.y, colCtx->subdivAmount.y, &colCtx->maxBounds.y,
                                    &colCtx->subdivLength.y, &colCtx->subdivLengthInv.y);
    BgCheck_SetSubdivisionDimension(colCtx->minBounds.z, colCtx->subdivAmount.z, &colCtx->maxBounds.z,
                                    &colCtx->subdivLength.z, &colCtx->subdivLengthInv.z);
    memSize = colCtx->subdivAmount.x * sizeof(StaticLookup) * colCtx->subdivAmount.y * colCtx->subdivAmount.z +
              colCtx->colHeader->numPolygons * sizeof(u8) + colCtx->dyna.polyNodesMax * sizeof(SSNode) +
              colCtx->dyna.polyListMax * sizeof(CollisionPoly) + colCtx->dyna.vtxListMax * sizeof(Vec3s) +
              sizeof(CollisionContext);
    if (customNodeListMax > 0) {
        
        
        tblMax = customNodeListMax;
    } else {
        if (colCtx->memSize < memSize) {
            Fault_AddHungupAndCrash("../z_bgcheck.c", LN1(4008, 4011));
        }
        tblMax = (colCtx->memSize - memSize) / sizeof(SSNode);
    }

    SSNodeList_Init(&colCtx->polyNodes);
    SSNodeList_Alloc(play, &colCtx->polyNodes, tblMax, colCtx->colHeader->numPolygons);

    lookupTblMemSize = BgCheck_InitStaticLookup(colCtx, play, colCtx->lookupTbl);

    DynaPoly_Init(play, &colCtx->dyna);
    DynaPoly_Alloc(play, &colCtx->dyna);
}
