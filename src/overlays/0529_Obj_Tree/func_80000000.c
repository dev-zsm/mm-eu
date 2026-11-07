// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tree.h"

void ObjTree_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjTree* this = (ObjTree*)thisx;
    CollisionHeader* colHeader = NULL;

    if (OBJTREE_ISLARGE(&this->dyna.actor)) {
        Actor_SetScale(&this->dyna.actor, 0.15f);
        this->dyna.actor.cullingVolumeDistance = 4000.0f;
    } else {
        Actor_SetScale(&this->dyna.actor, 0.1f);
        DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
        CollisionHeader_GetVirtual(&gTreeTopCol, &colHeader);
        this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
    }

    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&this->dyna.actor.colChkInfo, &sDamageTable, &sColchkInfoInit);

    if (OBJTREE_ISLARGE(&this->dyna.actor)) {
        this->collider.dim.height = 220;
    }

    this->swayAmplitude = 0.0f;
    this->swayAngle = 0;
    this->swayVelocity = 0;
    ObjTree_SetupDoNothing(this);
}
