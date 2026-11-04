// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Water_WallCheck(ObjMine* this, PlayState* play) {
    s32 pad; 
    ObjMineWaterChain* waterChain = &this->chain.water;

    waterChain->touchWall = false;
    if (waterChain->wallCheckDistSq > -1e-6f) {
        
        if (waterChain->wallCheckDistSq <= Math3D_Dist2DSq(this->actor.home.pos.x, this->actor.home.pos.z,
                                                           this->actor.world.pos.x, this->actor.world.pos.z)) {
            Vec3f centerPos;
            Vec3f offsetPos;
            Vec3f result; 
            Vec3f xzFromHome;
            Vec3f xzDirFromHome;
            CollisionPoly* poly; 
            s32 bgId;            
            f32 norm;            
            f32 invNorm;         

            xzFromHome.x = this->actor.world.pos.x - this->actor.home.pos.x;
            xzFromHome.y = 0.0f;
            xzFromHome.z = this->actor.world.pos.z - this->actor.home.pos.z;

            if (ObjMine_GetUnitVec3fNorm(&xzFromHome, &xzDirFromHome, &norm, &invNorm)) {

                offsetPos.x = this->actor.world.pos.x + (xzDirFromHome.x * WATER_RADIUS);
                offsetPos.y = this->actor.world.pos.y;
                offsetPos.z = this->actor.world.pos.z + (xzDirFromHome.z * WATER_RADIUS);

                centerPos.x = this->actor.home.pos.x;
                centerPos.y = this->actor.world.pos.y;
                centerPos.z = this->actor.home.pos.z;

                if (BgCheck_EntityLineTest1(&play->colCtx, &centerPos, &offsetPos, &result, &poly, true, false, false,
                                            true, &bgId)) {
                    waterChain->touchWall = true;
                    waterChain->wallEject.x = xzDirFromHome.x * -0.2f;
                    waterChain->wallEject.z = xzDirFromHome.z * -0.2f;
                }
            }
        }
    }
}
