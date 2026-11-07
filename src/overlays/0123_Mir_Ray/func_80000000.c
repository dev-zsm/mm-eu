// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray.h"

void MirRay_SetupCollider(MirRay* this) {
    MirRayDataEntry* dataEntry = &sMirRayData[MIRRAY_LOCATION(&this->actor)];
    f32 x = (this->poolPt.x - this->sourcePt.x) * dataEntry->unk_10;
    f32 y = (this->poolPt.y - this->sourcePt.y) * dataEntry->unk_10;
    f32 z = (this->poolPt.z - this->sourcePt.z) * dataEntry->unk_10;

    this->collider1.elements->dim.worldSphere.center.x = this->sourcePt.x + x;
    this->collider1.elements->dim.worldSphere.center.y = this->sourcePt.y + y;
    this->collider1.elements->dim.worldSphere.center.z = this->sourcePt.z + z;

    this->collider1.elements->dim.worldSphere.radius = dataEntry->unk_14 * this->collider1.elements->dim.scale;
}
