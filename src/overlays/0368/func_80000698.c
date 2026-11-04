// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Air_InitChain(ObjMine* this, s32 linkCount) {
    f32 linkCountF = linkCount;
    ObjMineAirChain* airChain = &this->chain.air;
    ObjMineAirLink* airLink;
    s32 i;
    f32 wallCheckRadius = this->actor.home.rot.z * 5.0f;

    airChain->basis.x.x = 1.0f;
    airChain->basis.y.y = 1.0f;
    airChain->basis.z.z = 1.0f;

    airChain->translation.y = 1.0f;

    
    if (linkCount > 0) {
        airChain->restore = -sqrtf((0.124992f / OBJMINE_CHAIN_MAX) / linkCountF);  
        airChain->drag = 0.95f + ((0.02000004f / OBJMINE_CHAIN_MAX) * linkCountF); 
    }

    airChain->swayMax = 0.0002f;

    
    for (i = 0, airLink = airChain->links; i < linkCount; i++, airLink++) {
        airLink->twist = 0x4000;
    }

    if (wallCheckRadius < 0.0f) {
        airChain->wallCheckDistSq = -1.0f; 
    } else if (wallCheckRadius <= AIR_RADIUS + 1.0f) {
        airChain->wallCheckDistSq = 0.0f;
    } else {
        airChain->wallCheckDistSq = SQ(wallCheckRadius - AIR_RADIUS);
    }
}
