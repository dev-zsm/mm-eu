// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_open_shutter.h"

void BgOpenShutter_Destroy(Actor* thisx, PlayState* play) {
    BgOpenShutter* this = (BgOpenShutter*)thisx;
    s32 transition = DOOR_GET_TRANSITION_ID(thisx);

    play->transitionActors.list[transition].id = -play->transitionActors.list[transition].id;
    DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->slidingDoor.dyna.bgId);
}
