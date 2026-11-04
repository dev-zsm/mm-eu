// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kendo_kanban.h"

void ObjKendoKanban_HandlePhysics(ObjKendoKanban* this, PlayState* play) {
    Vec3f rootCornerPos = this->cornerPos[0];
    s32 pad[2];
    Vec3f vecCenterOut = this->actor.world.pos;
    s32 pad2;
    s32 indexRootCornerPos = 0;
    s32 i;
    f32 verticalScalar;

    
    vecCenterOut.x -= this->centerPos.x;
    vecCenterOut.y -= this->centerPos.y;
    vecCenterOut.z -= this->centerPos.z;
    verticalScalar = (this->rotAxis.x * vecCenterOut.z) + (this->rotAxis.z * -vecCenterOut.x);
    if (verticalScalar < 0.0f) {
        this->angularVelocity += 0x64;
    } else {
        this->angularVelocity -= 0x64;
    }

    
    for (i = 0; i < ARRAY_COUNT(this->cornerPos); i++) {
        if (this->cornerPos[i].y < rootCornerPos.y) {
            rootCornerPos = this->cornerPos[i];
            indexRootCornerPos = i;
        }
    }

    
    if (indexRootCornerPos != this->indexLastRootCornerPos) {
        this->hasNewRootCornerPos = true;
        this->indexLastRootCornerPos = indexRootCornerPos;
        this->rootCornerPos = this->cornerPoints[indexRootCornerPos];

        Matrix_Push();
        Matrix_SetTranslateRotateYXZ(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z,
                                     &this->actor.shape.rot);
        Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
        Matrix_MultVec3f(&this->rootCornerPos, &this->actor.world.pos);
        this->actor.world.pos = rootCornerPos;
        this->actor.prevPos = this->actor.world.pos;
        Matrix_Pop();
    }

    Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);

    if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
        
        this->actor.velocity.x *= 0.8f;
        this->actor.velocity.z *= 0.8f;
    }

    if (this->hasNewRootCornerPos == true) {
        if (this->numBounces >= MAX_BOUNCE_COUNT) {
            s16 deltaRotAngle = this->rotAngle & 0x3FFF;

            if (deltaRotAngle >= 0x2000) { 
                deltaRotAngle -= 0x4000;   
            }
            this->rotAngle -= deltaRotAngle;
            this->angularVelocity = 0;
            ObjKendoKanban_SetupSettled(this);
            return;
        }

        if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND_TOUCH) {
            
            Actor_PlaySfx(&this->actor, NA_SE_EV_WOODPLATE_BOUND);
            this->hasNewRootCornerPos = false;
            this->actor.velocity.y *= 0.5f;
        } else if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
            
            this->numBounces++;
            this->hasNewRootCornerPos = false;
            this->actor.velocity.x *= 0.3f;
            this->actor.velocity.z *= 0.3f;
            Actor_PlaySfx(&this->actor, NA_SE_EV_WOODPLATE_BOUND);

            
            
            if (verticalScalar > 0.0f) {
                if (this->angularVelocity > 0) {
                    this->angularVelocity *= 1.2f;
                } else {
                    this->angularVelocity *= -0.6f;
                }
            } else {
                if (this->angularVelocity < 0) {
                    this->angularVelocity *= 1.2f;
                } else {
                    this->angularVelocity *= -0.6f;
                }
            }
        }
    }
}
