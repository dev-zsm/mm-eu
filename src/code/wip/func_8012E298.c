// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, bytes match; links once `gspS2DEX2_fifoDataStart` and the other symbols of the reference have names of ours
#include "generated/mm/z_room.h"

void Room_DrawImageSingle(PlayState* play, Room* room, u32 flags) {
    Camera* activeCam;
    Gfx* gfx;
    RoomShapeImageSingle* roomShape;
    RoomShapeDListsEntry* entry;
    u32 isFixedCamera;
    u32 drawBackground;
    u32 drawOpa;
    u32 drawXlu;

    OPEN_DISPS(play->state.gfxCtx);

    activeCam = GET_ACTIVE_CAM(play);
    isFixedCamera = false; 
    roomShape = &room->roomShape->image.single;
    entry = Lib_SegmentedToVirtual(roomShape->base.entry);
    drawBackground = (flags & ROOM_DRAW_OPA) && isFixedCamera && (roomShape->source != NULL) &&
                     !(R_ROOM_IMAGE_NODRAW_FLAGS & ROOM_IMAGE_NODRAW_BACKGROUND);
    drawOpa = (flags & ROOM_DRAW_OPA) && (entry->opa != NULL) && !(R_ROOM_IMAGE_NODRAW_FLAGS & ROOM_IMAGE_NODRAW_OPA);
    drawXlu = (flags & ROOM_DRAW_XLU) && (entry->xlu != NULL) && !(R_ROOM_IMAGE_NODRAW_FLAGS & ROOM_IMAGE_NODRAW_XLU);

    if (drawOpa || drawBackground) {
        gSPSegment(POLY_OPA_DISP++, 0x03, room->segment);

        if (drawOpa) {
            Gfx_SetupDL25_Opa(play->state.gfxCtx);
            gSPMatrix(POLY_OPA_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, entry->opa);
        }

        if (drawBackground) {
            gSPLoadUcodeL(POLY_OPA_DISP++, gspS2DEX2_fifo);

            gfx = POLY_OPA_DISP;

            {
                Vec3f quakeOffset;

                quakeOffset = Camera_GetQuakeOffset(activeCam);

                Prerender_DrawBackground2D(
                    &gfx, roomShape->source, roomShape->tlut, roomShape->width, roomShape->height, roomShape->fmt,
                    roomShape->siz, roomShape->tlutMode, roomShape->tlutCount,
                    (quakeOffset.x + quakeOffset.z) * 1.2f + quakeOffset.y * 0.6f,
                    quakeOffset.y * 2.4f + (quakeOffset.x + quakeOffset.z) * 0.3f, 1.0f, 1.0f, 0);
            }

            POLY_OPA_DISP = gfx;

            gSPLoadUcode(POLY_OPA_DISP++, SysUcode_GetUCode(), SysUcode_GetUCodeData());
        }
    }

    if (drawXlu) {
        gSPSegment(POLY_XLU_DISP++, 0x03, room->segment);
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        gSPMatrix(POLY_XLU_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, entry->xlu);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
