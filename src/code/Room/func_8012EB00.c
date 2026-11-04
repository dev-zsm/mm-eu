// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_room.h"

size_t Room_SetupFirstRoom(PlayState* play, RoomContext* roomCtx) {
    size_t roomBufferSize = 0;
    size_t roomSize;
    s32 i;
    s32 j;
    s32 frontRoom;
    s32 backRoom;
    size_t frontRoomSize;
    size_t backRoomSize;
    size_t cumulRoomSize;
    s32 pad[2];

    
    {
        RomFile* roomList = play->roomList.romFiles;

        for (i = 0; i < play->roomList.count; i++) {
            roomSize = roomList[i].vromEnd - roomList[i].vromStart;
            roomBufferSize = MAX(roomSize, roomBufferSize);
        }
    }

    
    if ((u32)play->transitionActors.count != 0) {
        RomFile* roomList = play->roomList.romFiles;
        TransitionActorEntry* transitionActor = &play->transitionActors.list[0];

        for (j = 0; j < play->transitionActors.count; j++) {
            frontRoom = transitionActor->sides[0].room;
            backRoom = transitionActor->sides[1].room;
            frontRoomSize = (frontRoom < 0) ? 0 : roomList[frontRoom].vromEnd - roomList[frontRoom].vromStart;
            backRoomSize = (backRoom < 0) ? 0 : roomList[backRoom].vromEnd - roomList[backRoom].vromStart;
            cumulRoomSize = (frontRoom != backRoom) ? frontRoomSize + backRoomSize : frontRoomSize;

            roomBufferSize = MAX(cumulRoomSize, roomBufferSize);
            transitionActor++;
        }
    }

    roomCtx->bufPtrs[0] = THA_AllocTailAlign16(&play->state.tha, roomBufferSize);
    if (roomCtx->bufPtrs[0] == NULL) {
        _dbg_hungup("../z_room.c", 1078);
    }
    roomCtx->bufPtrs[1] = (void*)((uintptr_t)roomCtx->bufPtrs[0] + roomBufferSize);
    roomCtx->activeBufPage = 0;
    roomCtx->status = 0;

    if ((gSaveContext.respawnFlag != 0) && (gSaveContext.respawnFlag != -2) && (gSaveContext.respawnFlag != -7)) {
        s32 respawnMode;

        if ((gSaveContext.respawnFlag == -8) || (gSaveContext.respawnFlag == -5) || (gSaveContext.respawnFlag == -4) ||
            ((gSaveContext.respawnFlag < 0) && (gSaveContext.respawnFlag != -1) && (gSaveContext.respawnFlag != -6))) {
            respawnMode = RESPAWN_MODE_DOWN;
        } else if (gSaveContext.respawnFlag < 0) {
            respawnMode = RESPAWN_MODE_TOP;
        } else {
            respawnMode = gSaveContext.respawnFlag - 1;
        }
        frontRoom = gSaveContext.respawn[respawnMode].roomIndex;
    } else {
        frontRoom = play->setupEntranceList[play->curSpawn].room;
    }

    
    
    
    Room_RequestNewRoom(play, roomCtx, frontRoom);

    return roomBufferSize;
}
