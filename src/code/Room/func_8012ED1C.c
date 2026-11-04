// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_room.h"

s32 Room_RequestNewRoom(PlayState* play, RoomContext* roomCtx, s32 index) {
    if (roomCtx->status == 0) {
        size_t size;

        roomCtx->prevRoom = roomCtx->curRoom;
        roomCtx->curRoom.num = index;
        roomCtx->curRoom.segment = NULL;
        roomCtx->status = 1;

        size = play->roomList.romFiles[index].vromEnd - play->roomList.romFiles[index].vromStart;
        roomCtx->roomRequestAddr = (void*)(ALIGN16((uintptr_t)roomCtx->bufPtrs[roomCtx->activeBufPage] -
                                                   (size + 8) * roomCtx->activeBufPage - 7));

        osCreateMesgQueue(&roomCtx->loadQueue, roomCtx->loadMsg, ARRAY_COUNT(roomCtx->loadMsg));
        DmaMgr_RequestAsync(&roomCtx->dmaRequest, roomCtx->roomRequestAddr, play->roomList.romFiles[index].vromStart,
                            size, 0, &roomCtx->loadQueue, NULL);
        roomCtx->activeBufPage ^= 1;

        return true;
    }

    return false;
}
