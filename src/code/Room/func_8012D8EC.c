// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_room.h"

void Room_DrawNormal(PlayState* play, Room* room, u32 flags) {
    RoomShapeNormal* roomShape;
    RoomShapeDListsEntry* entry;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    if (flags & ROOM_DRAW_OPA) {
        ref_func_800BCBF4(&sZeroVec, play);
        gSPSegment(POLY_OPA_DISP++, 0x03, room->segment);
        ref_func_8012C268(&play->state);
        gSPMatrix(POLY_OPA_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    }

    if (flags & ROOM_DRAW_XLU) {
        ref_func_800BCC68(&sZeroVec, play);
        gSPSegment(POLY_XLU_DISP++, 0x03, room->segment);
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        gSPMatrix(POLY_XLU_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    }

    roomShape = &room->roomShape->normal;
    entry = Lib_SegmentedToVirtual(roomShape->entries);
    for (i = 0; i < roomShape->numEntries; i++) {
        if ((flags & ROOM_DRAW_OPA) && (entry->opa != NULL)) {
            gSPDisplayList(POLY_OPA_DISP++, entry->opa);
        }

        if ((flags & ROOM_DRAW_XLU) && (entry->xlu != NULL)) {
            gSPDisplayList(POLY_XLU_DISP++, entry->xlu);
        }

        entry++;
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
