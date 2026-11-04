// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_room.h"

void Room_FinishRoomChange(PlayState* play, RoomContext* roomCtx) {
    
    roomCtx->prevRoom.num = -1;
    roomCtx->prevRoom.segment = NULL;

    ref_func_800BA798(play, &play->actorCtx);
    Actor_SpawnTransitionActors(play, &play->actorCtx);
    if (roomCtx->curRoom.num > -1) {
        Map_InitRoomData(play, roomCtx->curRoom.num);
        Map_SetAreaEntrypoint(play);
    }
    Audio_SetEnvReverb(play->roomCtx.curRoom.echo);
}
