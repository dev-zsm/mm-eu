// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_mirror.h"

void BgIkanaMirror_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    BgIkanaMirror* this = (BgIkanaMirror*)thisx;
    ColliderTrisElementInit* element;
    Vec3f vertices[3];
    s32 i;
    s32 j;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gStoneTowerTempleMirrorCol);
    Collider_InitTris(play, &this->mirrorCollider);
    Collider_SetTris(play, &this->mirrorCollider, &this->dyna.actor, &sMirrorColliderInit,
                     this->mirrorColliderElements);
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);

    for (i = 0; i < ARRAY_COUNT(sMirrorColliderElementsInit); i++) {
        element = &sMirrorColliderInit.elements[i];
        for (j = 0; j < 3; j++) {
            Matrix_MultVec3f(&element->dim.vtx[j], &vertices[j]);
        }
        Collider_SetTrisVertices(&this->mirrorCollider, i, &vertices[0], &vertices[1], &vertices[2]);
    }

    for (i = 0; i < ARRAY_COUNT(this->lightRaysColliders); i++) {
        Collider_InitQuad(play, &this->lightRaysColliders[i]);
        Collider_SetQuad(play, &this->lightRaysColliders[i], &this->dyna.actor, &sLightRaysCollidersInit[i]);
    }

    BgIkanaMirror_SetQuadVertices(this);
    this->lightAbsorptionTexScroll = Lib_SegmentedToVirtual(gStoneTowerTempleMirrorLightAbsorptionTexAnim);
    this->lightEmissionTexScroll = Lib_SegmentedToVirtual(gStoneTowerTempleMirrorLightEmissionTexAnim);
    BgIkanaMirror_SetupWait(this);
}
