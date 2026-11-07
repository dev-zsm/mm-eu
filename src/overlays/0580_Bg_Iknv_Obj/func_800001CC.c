// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_obj.h"

void BgIknvObj_Destroy(Actor* thisx, PlayState* play) {
    BgIknvObj* this = (BgIknvObj*)thisx;

    if (IKNV_OBJ_TYPE(this) != IKNV_OBJ_RAISED_DOOR) {
        if (IKNV_OBJ_TYPE(this) == IKNV_OBJ_SAKON_DOOR) {
            Collider_DestroyCylinder(play, &this->collider);
            CLEAR_WEEKEVENTREG(WEEKEVENTREG_51_10);
        } else {
            return;
        }
    }
    DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
}
