// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Water_ApplyForces(ObjMine* this) {
    ObjMineWaterChain* waterChain = &this->chain.water;
    ObjMineWaterLink* waterLink;
    s32 i;
    s16 swayPhase = 0;
    s32 linkCount = OBJMINE_GET_LINK_COUNT(&this->actor);
    f32 inverseCount = 1.0f / linkCount;
    f32 restoreY = (waterChain->links[linkCount - 1].pos.y - waterChain->restY) * waterChain->restoreY;
    Vec3f tension;
    f32 scaledKnockback;
    s32 index;
    s32 pad;
    Vec3f* lastLinkAccel;

    
    for (i = 0, waterLink = waterChain->links, lastLinkAccel = sLastLinkAccel; i < linkCount;
         i++, waterLink++, swayPhase += waterChain->swayPhaseVel, lastLinkAccel++) {
        Math_Vec3f_Copy(lastLinkAccel, &waterLink->accel);

        if (waterLink->pos.y <= this->actor.home.pos.y) {
            waterLink->accel.y = waterChain->restoreY * -96.0f;
        } else if (restoreY > 0.0f) {
            waterLink->accel.y = (i + 1) * inverseCount * (restoreY / 0.3f);
        } else {
            waterLink->accel.y = restoreY;
        }

        waterLink->accel.x = (waterLink->pos.x - this->actor.home.pos.x) * waterChain->restoreXZ;
        waterLink->accel.z = (waterLink->pos.z - this->actor.home.pos.z) * waterChain->restoreXZ;
        waterLink->accel.x += waterChain->swayXZ * Math_SinS(swayPhase);
        waterLink->accel.y += waterChain->swayY;
        waterLink->accel.z += waterChain->swayXZ * Math_CosS(swayPhase);
    }

    
    
    if (waterChain->knockback > 0.0001f) {
        for (i = 0, waterLink = waterChain->links; i < linkCount; i++, waterLink++) {
            scaledKnockback = SQ((linkCount - i) * inverseCount);

            waterLink->accel.x += waterChain->knockbackDir.x * scaledKnockback;
            waterLink->accel.y += waterChain->knockbackDir.y * scaledKnockback;
            waterLink->accel.z += waterChain->knockbackDir.z * scaledKnockback;
        }
    }

    
    if (waterChain->touchWall) {
        for (i = 0, waterLink = waterChain->links; i < linkCount; i++, waterLink++) {
            waterLink->accel.x += waterChain->wallEject.x;
            waterLink->accel.z += waterChain->wallEject.z;
        }
    }

    
    
    for (i = 0, waterLink = waterChain->links; i < linkCount; i++, waterLink++) {
        Math_Vec3f_Copy(&tension, &gZeroVec3f);

        if (i >= 2) {
            tension.x += sLastLinkAccel[i - 2].x * 0.075f;
            tension.y += sLastLinkAccel[i - 2].y * 0.075f;
            tension.z += sLastLinkAccel[i - 2].z * 0.075f;
        }

        if (i >= 1) {
            tension.x += sLastLinkAccel[i - 1].x * 0.15f;
            tension.y += sLastLinkAccel[i - 1].y * 0.15f;
            tension.z += sLastLinkAccel[i - 1].z * 0.15f;
        }

        tension.x += sLastLinkAccel[i].x * 0.3f;
        tension.y += sLastLinkAccel[i].y * 0.3f;
        tension.z += sLastLinkAccel[i].z * 0.3f;

        index = i + 1;
        if (index < linkCount) {
            tension.x += sLastLinkAccel[index].x * 0.15f;
            tension.y += sLastLinkAccel[index].y * 0.15f;
            tension.z += sLastLinkAccel[index].z * 0.15f;
        }

        index = i + 2;
        if (index < linkCount) {
            tension.x += sLastLinkAccel[index].x * 0.075f;
            tension.y += sLastLinkAccel[index].y * 0.075f;
            tension.z += sLastLinkAccel[index].z * 0.075f;
        }
        waterLink->accel.x += tension.x;
        waterLink->accel.y += tension.y;
        waterLink->accel.z += tension.z;
    }
}
