// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (ObjMine_Water_Stationary), score 1.00 (1 differ, size +1)
#include "generated/mm/z_obj_mine.h"

void func_80002B30(ObjMine* this, PlayState* play) {
    
    if (ObjMine_AirWater_CheckOC(this)) {
        ObjMine_AirWater_SpawnBomb(this, play);
        ObjMine_AirWater_Noop(this);
        ObjMine_SetupExplode(this);
        return;
    }

    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
}
