// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_room.h"

void Room_DrawCullable(PlayState* play, Room* room, u32 flags) {
    RoomShapeCullable* roomShape;
    RoomShapeCullableEntry* roomShapeCullableEntry;
    RoomShapeCullableEntryLinked linkedEntriesBuffer[ROOM_SHAPE_CULLABLE_MAX_ENTRIES];
    RoomShapeCullableEntryLinked* head = NULL;
    RoomShapeCullableEntryLinked* tail = NULL;
    RoomShapeCullableEntryLinked* iter;
    Gfx* dList;
    RoomShapeCullableEntryLinked* insert;
    f32 entryBoundsNearZ;
    s32 i;
    Vec3f pos;
    Vec3f projectedPos;
    RoomShapeCullableEntry* roomShapeCullableEntries;

    OPEN_DISPS(play->state.gfxCtx);

    if (flags & ROOM_DRAW_OPA) {
        ref_func_800BCBF4(&sZeroVec, play);

        gSPSegment(POLY_OPA_DISP++, 0x03, room->segment);
        if (play->roomCtx.unk74 != NULL) {
            gSPSegment(POLY_OPA_DISP++, 0x06, play->roomCtx.unk74);
        }
        ref_func_8012C268(&play->state);
        gSPMatrix(POLY_OPA_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    }

    if (flags & ROOM_DRAW_XLU) {
        ref_func_800BCC68(&sZeroVec, play);
        gSPSegment(POLY_XLU_DISP++, 0x03, room->segment);
        if (play->roomCtx.unk74 != NULL) {
            gSPSegment(POLY_XLU_DISP++, 0x06, play->roomCtx.unk74);
        }
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        gSPMatrix(POLY_XLU_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    }

    if (room->enablePosLights || (MREG(93) != 0)) {
        gSPSetGeometryMode(POLY_OPA_DISP++, G_LIGHTING_POSITIONAL);
        gSPSetGeometryMode(POLY_XLU_DISP++, G_LIGHTING_POSITIONAL);
    }

    roomShape = &room->roomShape->cullable;
    roomShapeCullableEntry = Lib_SegmentedToVirtual(roomShape->entries);
    insert = linkedEntriesBuffer;

    roomShapeCullableEntries = roomShapeCullableEntry;

    if (play->roomCtx.unk78 < 0) {
        for (i = 0; i < roomShape->numEntries; i++, roomShapeCullableEntry++) {
            if (R_ROOM_CULL_DEBUG_MODE != 0) {
                if (((R_ROOM_CULL_DEBUG_MODE == ROOM_CULL_DEBUG_MODE_UP_TO_TARGET) &&
                     (i <= R_ROOM_CULL_DEBUG_TARGET)) ||
                    ((R_ROOM_CULL_DEBUG_MODE == ROOM_CULL_DEBUG_MODE_ONLY_TARGET) && (i == R_ROOM_CULL_DEBUG_TARGET))) {
                    if (flags & ROOM_DRAW_OPA) {
                        dList = roomShapeCullableEntry->opa;
                        if (dList != NULL) {
                            gSPDisplayList(POLY_OPA_DISP++, dList);
                        }
                    }

                    if (flags & ROOM_DRAW_XLU) {
                        dList = roomShapeCullableEntry->xlu;
                        if (dList != NULL) {
                            gSPDisplayList(POLY_XLU_DISP++, dList);
                        }
                    }
                }
            } else {
                if (flags & ROOM_DRAW_OPA) {
                    dList = roomShapeCullableEntry->opa;
                    if (dList != NULL) {
                        gSPDisplayList(POLY_OPA_DISP++, dList);
                    }
                }

                if (flags & ROOM_DRAW_XLU) {
                    dList = roomShapeCullableEntry->xlu;
                    if (dList != NULL) {
                        gSPDisplayList(POLY_XLU_DISP++, dList);
                    }
                }
            }
        }
    } else {
        f32 var_fa1 = 1.0f / play->projectionMtxFDiagonal.z;
        f32 var_fv1;
        s32 var_a1;

        
        for (i = 0; i < roomShape->numEntries; i++, roomShapeCullableEntry++) {

            
            pos.x = roomShapeCullableEntry->boundsSphereCenter.x;
            pos.y = roomShapeCullableEntry->boundsSphereCenter.y;
            pos.z = roomShapeCullableEntry->boundsSphereCenter.z;
            SkinMatrix_Vec3fMtxFMultXYZ(&play->viewProjectionMtxF, &pos, &projectedPos);

            projectedPos.z *= var_fa1;

            var_fv1 = ABS_ALT(roomShapeCullableEntry->boundsSphereRadius);

            
            if (-var_fv1 < projectedPos.z) {

                
                entryBoundsNearZ = projectedPos.z - var_fv1;

                
                if (entryBoundsNearZ < play->lightCtx.zFar) {

                    
                    insert->entry = roomShapeCullableEntry;

                    if (roomShapeCullableEntry->boundsSphereRadius < 0) {
                        insert->boundsNearZ = FLT_MAX;
                    } else {
                        insert->boundsNearZ = entryBoundsNearZ;
                    }

                    
                    
                    iter = head;
                    if (iter == NULL) {
                        head = tail = insert;
                        insert->prev = insert->next = NULL;
                    } else {
                        do {
                            if (insert->boundsNearZ < iter->boundsNearZ) {
                                break;
                            }
                            iter = iter->next;
                        } while (iter != NULL);

                        if (iter == NULL) {
                            insert->prev = tail;
                            insert->next = NULL;
                            tail->next = insert;
                            tail = insert;
                        } else {
                            insert->prev = iter->prev;
                            if (insert->prev == NULL) {
                                head = insert;
                            } else {
                                insert->prev->next = insert;
                            }
                            iter->prev = insert;
                            insert->next = iter;
                        }
                    }

                    insert++;
                }
            }
        }

        
        R_ROOM_CULL_NUM_ENTRIES = roomShape->numEntries & 0xFFFF & 0xFFFF & 0xFFFF;

        
        i = 1;

        if (flags & ROOM_DRAW_OPA) {
            for (; head != NULL; head = head->next, i++) {
                s32 pad;

                roomShapeCullableEntry = head->entry;

                if (R_ROOM_CULL_DEBUG_MODE != ROOM_CULL_DEBUG_MODE_OFF) {
                    

                    if (((R_ROOM_CULL_DEBUG_MODE == ROOM_CULL_DEBUG_MODE_UP_TO_TARGET) &&
                         (i <= R_ROOM_CULL_DEBUG_TARGET)) ||
                        ((R_ROOM_CULL_DEBUG_MODE == ROOM_CULL_DEBUG_MODE_ONLY_TARGET) &&
                         (i == R_ROOM_CULL_DEBUG_TARGET))) {

                        dList = roomShapeCullableEntry->opa;
                        if (dList != NULL) {
                            gSPDisplayList(POLY_OPA_DISP++, dList);
                        }
                    }
                } else {
                    dList = roomShapeCullableEntry->opa;
                    if (dList != NULL) {
                        gSPDisplayList(POLY_OPA_DISP++, dList);
                    }
                }
            }
        }

        if (flags & ROOM_DRAW_XLU) {
            for (; tail != NULL; tail = tail->prev) {
                f32 temp_fv0;
                f32 temp_fv1;

                roomShapeCullableEntry = tail->entry;
                dList = roomShapeCullableEntry->xlu;

                if (dList != NULL) {
                    if (roomShapeCullableEntry->boundsSphereRadius & 1) {

                        temp_fv0 = tail->boundsNearZ - (f32)(iREG(93) + 0xBB8);
                        temp_fv1 = iREG(94) + 0x7D0;

                        if (temp_fv0 < temp_fv1) {
                            if (temp_fv0 < 0.0f) {
                                var_a1 = 255;
                            } else {
                                var_a1 = 255 - (s32)((temp_fv0 / temp_fv1) * 255.0f);
                            }
                            gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, var_a1);
                            gSPDisplayList(POLY_XLU_DISP++, dList);
                        }
                    } else {
                        gSPDisplayList(POLY_XLU_DISP++, dList);
                    }
                }
            }
        }

        R_ROOM_CULL_USED_ENTRIES = i - 1;
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
