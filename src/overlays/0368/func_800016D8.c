// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Water_UpdateLinks(ObjMine* this) {
    s32 pad; 
    ObjMineMtxF3 newBasis;
    s32 linkCount = OBJMINE_GET_LINK_COUNT(&this->actor);
    ObjMineWaterChain* waterChain = &this->chain.water;
    ObjMineWaterLink* waterLink;
    s32 i;
    Vec3f* prevBasisX;
    Vec3f tempVec;
    Vec3f diffDir;
    Vec3f unusedLinkPos;
    Vec3f jointPos;
    s32 changeBasis;
    f32 diffNorm;
    f32 invNorm; 
    Vec3f* tempBasisX;

    
    
    jointPos.x = this->actor.home.pos.x;
    jointPos.y = this->actor.home.pos.y + (LINK_SIZE / 2.0f);
    jointPos.z = this->actor.home.pos.z;

    for (i = 0, prevBasisX = NULL, waterLink = waterChain->links; i < linkCount;
         i++, prevBasisX = &waterLink->basis.x, waterLink++) {
        changeBasis = false;

        waterLink->velocity.x += waterLink->accel.x;
        waterLink->velocity.y += waterLink->accel.y;
        waterLink->velocity.z += waterLink->accel.z;

        Math_Vec3f_Scale(&waterLink->velocity, waterChain->drag);
        Math_Vec3f_Copy(&unusedLinkPos, &waterLink->pos);

        waterLink->pos.x += waterLink->velocity.x;
        waterLink->pos.y += waterLink->velocity.y;
        waterLink->pos.z += waterLink->velocity.z;

        
        if ((waterLink->pos.y <= this->actor.home.pos.y) && (waterLink->velocity.y < 0.0f)) {
            waterLink->velocity.y *= 0.1f;
        }

        
        
        
        Math_Vec3f_Diff(&waterLink->pos, &jointPos, &tempVec);

        if (ObjMine_GetUnitVec3fNorm(&tempVec, &diffDir, &diffNorm, &invNorm) && (diffNorm > LINK_SIZE / 3.0f)) {
            Math_Vec3f_Copy(&newBasis.y, &waterLink->basis.y);
            ObjMine_StepUntilParallel(&newBasis.y, &diffDir, M_PIf / 30);

            tempBasisX = (prevBasisX == NULL) ? &sStandardBasis.x : prevBasisX;

            Math3D_Vec3f_Cross(tempBasisX, &newBasis.y, &tempVec);

            
            if (ObjMine_GetUnitVec3f(&tempVec, &newBasis.z)) {
                Math3D_Vec3f_Cross(&newBasis.y, &newBasis.z, &tempVec);
                if (ObjMine_GetUnitVec3f(&tempVec, &newBasis.x)) {
                    changeBasis = true;
                }
            }
        }

        if (changeBasis) {
            Math_Vec3f_Copy(&waterLink->basis.x, &newBasis.x);
            Math_Vec3f_Copy(&waterLink->basis.y, &newBasis.y);
            Math_Vec3f_Copy(&waterLink->basis.z, &newBasis.z);
        } else {
            diffNorm = LINK_SIZE / 3.0f;
        }

        
        
        if (diffNorm >= (LINK_SIZE / 2.0f)) {
            waterLink->pos.x = jointPos.x + (waterLink->basis.y.x * (LINK_SIZE / 2.0f));
            waterLink->pos.y = jointPos.y + (waterLink->basis.y.y * (LINK_SIZE / 2.0f));
            waterLink->pos.z = jointPos.z + (waterLink->basis.y.z * (LINK_SIZE / 2.0f));
        } else {
            waterLink->pos.x = jointPos.x + (waterLink->basis.y.x * diffNorm);
            waterLink->pos.y = jointPos.y + (waterLink->basis.y.y * diffNorm);
            waterLink->pos.z = jointPos.z + (waterLink->basis.y.z * diffNorm);
        }

        
        jointPos.x = waterLink->pos.x + (waterLink->basis.y.x * (LINK_SIZE / 2.0f));
        jointPos.y = waterLink->pos.y + (waterLink->basis.y.y * (LINK_SIZE / 2.0f));
        jointPos.z = waterLink->pos.z + (waterLink->basis.y.z * (LINK_SIZE / 2.0f));
    }
}
