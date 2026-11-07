// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_takaraya_wall.h"

void ObjTakarayaWall_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjTakarayaWall* this = (ObjTakarayaWall*)thisx;

    this->actionFunc(this, play);

    CollisionCheck_SetOC(play, &play->colChkCtx, &this->columnCollider.base);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->rowCollider.base);
}
