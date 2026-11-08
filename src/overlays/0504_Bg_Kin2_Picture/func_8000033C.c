// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_picture.h"

void BgKin2Picture_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgKin2Picture* this = (BgKin2Picture*)thisx;
    s32 skulltulaParams;
    Vec3f vertices[3];
    s32 i;
    s32 j;
    ColliderTrisElementInit* element;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gOceanSpiderHouseSkullkidPaintingCol);
    DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
    Collider_InitTris(play, &this->colliderTris);
    Collider_SetTris(play, &this->colliderTris, &this->dyna.actor, &sTrisInit, this->colliderElement);
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);

    for (i = 0; i < ARRAY_COUNT(sTrisElementsInit); i++) {
        for (j = 0; j < ARRAY_COUNT(vertices); j++) {
            element = &sTrisInit.elements[i];
            Matrix_MultVec3f(&element->dim.vtx[j], &vertices[j]);
        }
        Collider_SetTrisVertices(&this->colliderTris, i, &vertices[0], &vertices[1], &vertices[2]);
    }

    Actor_SetFocus(&this->dyna.actor, 23.0f);
    skulltulaParams = BG_KIN2_PICTURE_SKULLTULA_SPAWN_PARAM(&this->dyna.actor);

    if (BG_KIN2_PICTURE_SKULLTULA_COLLECTED(&this->dyna.actor) ||
        BgKin2Picture_IsSkulltulaCollected(play, skulltulaParams)) {
        this->skulltulaNoiseTimer = -1;
    }

    BgKin2Picture_SetupWait(this);
}
