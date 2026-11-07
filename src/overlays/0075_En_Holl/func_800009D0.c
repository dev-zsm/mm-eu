// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_RoomTransitionIdle(EnHoll* this, PlayState* play) {
    if (play->roomCtx.status == 0) {
        Room_FinishRoomChange(play, &play->roomCtx);
        if (play->bgCoverAlpha == 0) {
            this->bgCoverAlphaActive = false;
        }
        EnHoll_SetupAction(this);
    }
}
