// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

void StaticLookup_AddPolyToSSList(CollisionContext* colCtx, SSList* ssList, CollisionPoly* polyList, Vec3s* vtxList,
                                  s16 polyId) {
    SSNode* curNode;
    SSNode* nextNode;
    s32 polyYMin;
    u16 newNodeId;
    s16 curPolyId;

    
    if (ssList->head == SS_NULL) {
        SSNodeList_SetSSListHead(&colCtx->polyNodes, ssList, &polyId);
        return;
    }

    polyYMin = CollisionPoly_GetMinY(&polyList[polyId], vtxList);

    curNode = &colCtx->polyNodes.tbl[ssList->head];
    curPolyId = curNode->polyId;

    
    if ((polyYMin < vtxList[COLPOLY_VTX_INDEX(polyList[curPolyId].flags_vIA)].y) &&
        (polyYMin < vtxList[COLPOLY_VTX_INDEX(polyList[curPolyId].flags_vIB)].y) &&
        (polyYMin < vtxList[polyList[curPolyId].vIC].y)) {
        SSNodeList_SetSSListHead(&colCtx->polyNodes, ssList, &polyId);
        return;
    }
    while (true) {
        
        if (curNode->next == SS_NULL) {
            s32 pad;

            newNodeId = SSNodeList_GetNextNodeIdx(&colCtx->polyNodes);
            SSNode_SetValue(&colCtx->polyNodes.tbl[newNodeId], &polyId, SS_NULL);
            curNode->next = newNodeId;
            break;
        }

        nextNode = &colCtx->polyNodes.tbl[curNode->next];
        curPolyId = nextNode->polyId;

        
        if ((polyYMin < vtxList[COLPOLY_VTX_INDEX(polyList[curPolyId].flags_vIA)].y) &&
            (polyYMin < vtxList[COLPOLY_VTX_INDEX(polyList[curPolyId].flags_vIB)].y) &&
            (polyYMin < vtxList[polyList[curPolyId].vIC].y)) {
            newNodeId = SSNodeList_GetNextNodeIdx(&colCtx->polyNodes);
            SSNode_SetValue(&colCtx->polyNodes.tbl[newNodeId], &polyId, curNode->next);
            curNode->next = newNodeId;
            break;
        }
        curNode = nextNode;
    }
}
