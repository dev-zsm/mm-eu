// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    BgNumaHana* this = (BgNumaHana*)thisx;
    s32 type = BG_NUMA_HANA_GET_TYPE(&this->dyna.actor);
    Vec3f firePos;

    if (type == BG_NUMA_HANA_TYPE_NORMAL) {
        firePos.x = this->dyna.actor.world.pos.x;
        firePos.y = this->dyna.actor.world.pos.y + 10.5f;
        firePos.z = this->dyna.actor.world.pos.z;
        FireObj_SetPosition(&this->fire, &firePos);
        FireObj_Update(play, &this->fire, &this->dyna.actor);
    }

    this->actionFunc(this, play);

    if (type == BG_NUMA_HANA_TYPE_NORMAL) {
        this->dyna.actor.child->shape.rot = this->dyna.actor.shape.rot;
        Collider_UpdateCylinder(&this->dyna.actor, &this->torchCollider);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->torchCollider.base);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->torchCollider.base);
    }
}
