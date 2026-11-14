// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_8000167C(Actor* thisx, PlayState* play, Skin* skin) {
    Vec3f sp4C;
    Vec3f sp40;
    EnHorseLinkChild* this = (EnHorseLinkChild*)thisx;
    s32 i;

    for (i = 0; i < this->colliderJntSph.count; i++) {
        sp4C.x = this->colliderJntSph.elements[i].dim.modelSphere.center.x;
        sp4C.y = this->colliderJntSph.elements[i].dim.modelSphere.center.y;
        sp4C.z = this->colliderJntSph.elements[i].dim.modelSphere.center.z;

        Skin_GetLimbPos(skin, this->colliderJntSph.elements[i].dim.limb, &sp4C, &sp40);

        this->colliderJntSph.elements[i].dim.worldSphere.center.x = sp40.x;
        this->colliderJntSph.elements[i].dim.worldSphere.center.y = sp40.y;
        this->colliderJntSph.elements[i].dim.worldSphere.center.z = sp40.z;
        this->colliderJntSph.elements[i].dim.worldSphere.radius =
            this->colliderJntSph.elements[i].dim.modelSphere.radius * this->colliderJntSph.elements[i].dim.scale;
    }

    CollisionCheck_SetOC(play, &play->colChkCtx, &this->colliderJntSph.base);
}
