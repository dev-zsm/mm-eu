// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_ravine.h"

void DmRavine_Update(Actor* thisx, PlayState* play) {
    DmRavine* this = (DmRavine*)thisx;
    RoomContext* roomCtx;

    switch (this->state) {
        case DM_RAVINE_STATE_INITIALIZED:
            break;

        case DM_RAVINE_STATE_ACTIVE:
            this->isActive = true;
            play->roomCtx.unk7A[1]++;
            if (play->roomCtx.unk7A[1] > 254) {
                play->roomCtx.unk7A[1] = 254;
                if (play->csCtx.curFrame > 700) {
                    play->roomCtx.unk7A[1] = 255;
                    play->roomCtx.unk7A[0] = 0;
                    this->state++; 
                }
            }
            break;

        case DM_RAVINE_STATE_PENDING_DEATH:
            Actor_Kill(&this->actor);
            break;

        default:
            break;
    }
}
