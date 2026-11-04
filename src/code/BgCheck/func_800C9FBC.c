// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_FindWaterBox(PlayState* play, CollisionContext* colCtx, Vec3f* pos, f32 surfaceCheckDist,
                         WaterBox** outWaterBox, s32* outBgId) {
    CollisionHeader* colHeader;
    s32 room;
    s32 i;
    WaterBox* waterBox;
    BgActor* bgActor;

    *outBgId = BGCHECK_SCENE;
    colHeader = colCtx->colHeader;

    
    if ((colHeader->numWaterBoxes == 0) || (colHeader->waterBoxes == NULL)) {
        *outWaterBox = NULL;
        return -1;
    }

    for (i = 0; i < colHeader->numWaterBoxes; i++) {
        waterBox = &colHeader->waterBoxes[i];

        room = WATERBOX_ROOM((s32)waterBox->properties);
        if ((room != play->roomCtx.curRoom.num) && (room != WATERBOX_ROOM_ALL)) {
            continue;
        }
        if (waterBox->properties & WATERBOX_IS_DISABLED) {
            continue;
        }
        
        if ((waterBox->minPos.x < pos->x) && (pos->x < waterBox->minPos.x + waterBox->xLength)) {
            if ((waterBox->minPos.z < pos->z) && (pos->z < waterBox->minPos.z + waterBox->zLength)) {
                if ((pos->y - surfaceCheckDist < waterBox->minPos.y) &&
                    (waterBox->minPos.y < pos->y + surfaceCheckDist)) {
                    *outWaterBox = waterBox;
                    return i;
                }
            }
        }
    }

    for (i = 0; i < BG_ACTOR_MAX; i++) {

        if (!(colCtx->dyna.bgActorFlags[i] & BGACTOR_IN_USE) ||
            (colCtx->dyna.bgActorFlags[i] & BGACTOR_COLLISION_DISABLED) || (colCtx->dyna.bgActorFlags[i] & BGACTOR_1)) {
            continue;
        }
        bgActor = &colCtx->dyna.bgActors[i];
        for (waterBox = colCtx->dyna.waterBoxList.boxes + bgActor->waterboxesStartIndex;
             waterBox <
             colCtx->dyna.waterBoxList.boxes + bgActor->waterboxesStartIndex + bgActor->colHeader->numWaterBoxes;
             waterBox++) {
            if (waterBox->properties & WATERBOX_IS_DISABLED) {
                continue;
            }
            
            if ((waterBox->minPos.x < pos->x) && (pos->x < waterBox->minPos.x + waterBox->xLength)) {
                if ((waterBox->minPos.z < pos->z) && (pos->z < waterBox->minPos.z + waterBox->zLength)) {
                    if ((pos->y - surfaceCheckDist < waterBox->minPos.y) &&
                        (waterBox->minPos.y < pos->y + surfaceCheckDist)) {
                        *outBgId = i;
                        *outWaterBox = waterBox;
                        return i;
                    }
                }
            }
        }
    }

    *outWaterBox = NULL;
    return -1;
}
