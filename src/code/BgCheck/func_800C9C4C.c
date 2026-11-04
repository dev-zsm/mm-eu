// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_GetWaterSurface(PlayState* play, CollisionContext* colCtx, f32 x, f32 z, f32* outWaterSurface,
                            WaterBox** outWaterBox, s32* outBgId) {
    CollisionHeader* colHeader;
    s32 room;
    s32 i;
    WaterBox* curWaterBox;
    BgActor* bgActor;

    *outBgId = BGCHECK_SCENE;
    colHeader = colCtx->colHeader;

    if ((colHeader->numWaterBoxes != 0) && (colHeader->waterBoxes != NULL)) {
        for (curWaterBox = colHeader->waterBoxes; curWaterBox < colHeader->waterBoxes + colHeader->numWaterBoxes;
             curWaterBox++) {
            room = (s32)WATERBOX_ROOM(curWaterBox->properties);
            if ((room != play->roomCtx.curRoom.num) && (room != WATERBOX_ROOM_ALL)) {
                continue;
            }
            if (curWaterBox->properties & WATERBOX_IS_DISABLED) {
                continue;
            }
            
            
            
            if ((curWaterBox->minPos.x < x) && (x < curWaterBox->minPos.x + curWaterBox->xLength)) {
                if ((curWaterBox->minPos.z < z) && (z < curWaterBox->minPos.z + curWaterBox->zLength)) {
                    *outWaterBox = curWaterBox;
                    *outWaterSurface = curWaterBox->minPos.y;
                    return true;
                }
            }
        }
    }

    for (i = 0; i < BG_ACTOR_MAX; i++) {
        if (!(colCtx->dyna.bgActorFlags[i] & BGACTOR_IN_USE) ||
            (colCtx->dyna.bgActorFlags[i] & BGACTOR_COLLISION_DISABLED)) {
            continue;
        }
        bgActor = &colCtx->dyna.bgActors[i];
        if ((bgActor->colHeader->numWaterBoxes != 0) && (bgActor->colHeader->waterBoxes != NULL)) {
            for (curWaterBox = colCtx->dyna.waterBoxList.boxes + bgActor->waterboxesStartIndex;
                 curWaterBox <
                 colCtx->dyna.waterBoxList.boxes + bgActor->waterboxesStartIndex + bgActor->colHeader->numWaterBoxes;
                 curWaterBox++) {
                if (curWaterBox->properties & WATERBOX_IS_DISABLED) {
                    continue;
                }
                
                if ((curWaterBox->minPos.x < x) && (x < curWaterBox->minPos.x + curWaterBox->xLength)) {
                    if ((curWaterBox->minPos.z < z) && (z < curWaterBox->minPos.z + curWaterBox->zLength)) {
                        *outWaterBox = curWaterBox;
                        *outWaterSurface = curWaterBox->minPos.y;
                        *outBgId = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
