// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Water_Chained(ObjMine* this, PlayState* play) {
    ObjMineWaterChain* waterChain = &this->chain.water;

    
    if (ObjMine_AirWater_CheckOC(this)) {
        ObjMine_AirWater_SpawnBomb(this, play);
        ObjMine_AirWater_Noop(this);
        ObjMine_SetupExplode(this);
        return;
    }

    
    if (this->collider.base.acFlags & AC_HIT) {
        this->collider.base.acFlags &= ~AC_HIT;
        ObjMine_Water_CheckAC(this, &waterChain->knockbackDir);
        waterChain->knockback = WATER_KNOCKBACK;
        Math_Vec3f_Scale(&waterChain->knockbackDir, WATER_KNOCKBACK);
    }

    
    if (waterChain->knockback > 0.0001f) {
        waterChain->knockback = Math_Vec3f_StepTo(&waterChain->knockbackDir, &gZeroVec3f, WATER_KNOCKBACK * 0.4f);
    }

    waterChain->drag = 0.9f;
    waterChain->restoreXZ = -0.0002f;
    waterChain->restoreY = -0.0002f;
    waterChain->swayMax = 0.003f;

    
    if (Rand_Next() >> (0x20 - 5) == 0) {
        s16 randAngle = Rand_Next() >> (0x20 - 16);

        waterChain->swayXZ = Math_SinS(randAngle) * 1.8f * waterChain->swayMax;
        waterChain->swayY = Math_CosS(randAngle) * 0.2f * waterChain->swayMax;
        waterChain->swayPhaseVel = Rand_Next() >> (0x20 - 13);
    }

    ObjMine_Water_UpdateChain(this, play);
    ObjMine_Water_SetWorld(this);
    ObjMine_UpdateCollider(this);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
}
