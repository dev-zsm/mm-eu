// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_InitTrisCollider(Actor* thisx, PlayState* play, ColliderTrisInit* init) {
    ObjSwitch* this = (ObjSwitch*)thisx;
    s32 i;
    s32 j;
    Vec3f vtx[3];

    Collider_InitTris(play, &this->colliderTris);
    Collider_SetTris(play, &this->colliderTris, &this->dyna.actor, init, this->colliderTrisElements);
    Matrix_Push();
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x,
                                 this->dyna.actor.world.pos.y +
                                     this->dyna.actor.shape.yOffset * this->dyna.actor.scale.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);

    for (i = 0; i < ARRAY_COUNT(this->colliderTrisElements); i++) {
        for (j = 0; j < ARRAY_COUNT(vtx); j++) {
            Matrix_MultVec3f(&init->elements[i].dim.vtx[j], &vtx[j]);
        }
        Collider_SetTrisVertices(&this->colliderTris, i, &vtx[0], &vtx[1], &vtx[2]);
    }
    Matrix_Pop();
}
