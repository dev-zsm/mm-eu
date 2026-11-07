// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_milk_bin.h"

void ObjMilkBin_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjMilkBin* this = (ObjMilkBin*)thisx;

    if (this->type == OBJ_MILK_BIN_TYPE_1) {
        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS)) {
            if (((gSaveContext.save.day == 2) && (gSaveContext.save.isNight == 1)) || (gSaveContext.save.day >= 3)) {
                Actor_Kill(&this->actor);
                return;
            }
        }
    } else if (this->type == OBJ_MILK_BIN_TYPE_2) {
        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_ESCORTED_CREMIA)) {
            this->disableDraw &= ~1;
        } else {
            this->disableDraw |= 1;
        }
    }

    if (!(this->disableDraw & 1)) {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }
}
