// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_obj.h"

void ref_func_80BD7ED8(BgIknvObj* this, PlayState* play) {
    if (ref_func_80BD7E0C(this, this->dyna.actor.home.rot.y, play)) {
        this->actionFunc = BgIknvObj_UpdateSakonDoor;
        CLEAR_WEEKEVENTREG(WEEKEVENTREG_51_10);
    }
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}
