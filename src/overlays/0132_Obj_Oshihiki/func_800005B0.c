// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

void ObjOshihiki_SetFloors(ObjOshihiki* this, PlayState* play) {
    s32 pad;
    Vec3f colCheckPoint;
    Vec3f colCheckOffset;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sColCheckPoints); i++) {
        colCheckOffset.x = sColCheckPoints[i].x * (this->dyna.actor.scale.x * 10.0f);
        colCheckOffset.y = sColCheckPoints[i].y * (this->dyna.actor.scale.y * 10.0f);
        colCheckOffset.z = sColCheckPoints[i].z * (this->dyna.actor.scale.z * 10.0f);

        ObjOshihiki_RotateXZ(&colCheckPoint, &colCheckOffset, this->yawSin, this->yawCos);

        colCheckPoint.x += this->dyna.actor.world.pos.x;
        colCheckPoint.y += this->dyna.actor.prevPos.y;
        colCheckPoint.z += this->dyna.actor.world.pos.z;

        this->floorHeights[i] = BgCheck_EntityRaycastFloor6(&play->colCtx, &this->floorPolys[i], &this->floorBgIds[i],
                                                            &this->dyna.actor, &colCheckPoint, 0.0f);
    }
}
