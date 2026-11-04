// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako2.h"

s32 ObjKibako2_ShouldBreak(ObjKibako2* this) {
    u8 acFlags = this->collider.base.acFlags;
    s32 shouldBreak = false;

    if (this->collider.base.acFlags & AC_HIT) {
        Actor* ac = this->collider.base.ac;
        this->collider.base.acFlags = acFlags & ~AC_HIT;
        if (ac != NULL) {
            if (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & (1 << 31)) {
                
                if (Math3D_Vec3fDistSq(&this->dyna.actor.world.pos, &ac->world.pos) < SQ(160.0f)) {
                    shouldBreak = true;
                }
            } else if (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & (1 << 3)) {
                
                if (Math3D_Vec3fDistSq(&this->dyna.actor.world.pos, &ac->world.pos) < SQ(100.0f)) {
                    shouldBreak = true;
                }
            } else if (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & (1 << 8 | 1 << 10)) {
                
                shouldBreak = true;
            }
        }
    } else if (this->dyna.actor.home.rot.z != 0) {
        shouldBreak = true;
    }
    return shouldBreak;
}
