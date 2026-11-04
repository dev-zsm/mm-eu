// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_ChangeRooms(PlayState* play) {
    Room tempRoom = play->roomCtx.curRoom;

    play->roomCtx.curRoom = play->roomCtx.prevRoom;
    play->roomCtx.prevRoom = tempRoom;
    play->roomCtx.activeBufPage ^= 1;
}
