// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Water_InitChain(ObjMine* this, s32 linkCount) {
    ObjMineWaterChain* waterChain = &this->chain.water;
    ObjMineWaterLink* waterLink;
    s32 i;
    f32 wallCheckRadius = this->actor.home.rot.z * 5.0f;
    f32 linkY;
    f32 swayVel;

    waterChain->drag = 0.9f;
    waterChain->swayMax = 0.003f;

    waterChain->swayPhaseVel = Rand_Next() >> (0x20 - 13);
    waterChain->restoreXZ = -0.0002f;
    waterChain->restoreY = -0.0002f;

    swayVel = waterChain->swayMax * (LINK_SIZE / 2.0f);
    linkY = this->actor.home.pos.y;

    for (i = 0, waterLink = waterChain->links; i < linkCount; i++, waterLink++) {
        linkY += LINK_SIZE;
        waterLink->basis.x.x = 1.0f;
        waterLink->basis.y.y = 1.0f;
        waterLink->basis.z.z = 1.0f;
        waterLink->pos.x = this->actor.home.pos.x;
        waterLink->pos.y = linkY;
        waterLink->pos.z = this->actor.home.pos.z;
        waterLink->velocity.x = (Rand_ZeroOne() - 0.5f) * swayVel;
        waterLink->velocity.y = (Rand_ZeroOne() - 0.5f) * swayVel;
        waterLink->velocity.z = (Rand_ZeroOne() - 0.5f) * swayVel;
    }
    waterChain->maxY = linkY;

    
    waterChain->restY = waterChain->maxY * 0.97f;
    linkY -= LINK_SIZE * 1.5f;
    if (waterChain->restY < linkY) { 
        waterChain->restY = linkY;
    }

    if (wallCheckRadius < 0.0f) {
        waterChain->wallCheckDistSq = -1.0f; 
    } else if (wallCheckRadius <= WATER_RADIUS + 1.0f) {
        waterChain->wallCheckDistSq = 0.0f;
    } else {
        waterChain->wallCheckDistSq = SQ(wallCheckRadius - WATER_RADIUS);
    }
}
