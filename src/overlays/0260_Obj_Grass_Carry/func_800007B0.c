// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_carry.h"

void ObjGrassCarry_LiftedUp(ObjGrassCarry* this, PlayState* play) {
    s32 pad;

    if (Actor_HasNoParent(&this->actor, play)) {
        ObjGrassCarry_SetupFall(this);
        this->actor.velocity.x = Math_SinS(this->actor.world.rot.y) * this->actor.speed;
        this->actor.velocity.z = Math_CosS(this->actor.world.rot.y) * this->actor.speed;
        this->actor.gravity = -0.1f;
        this->actor.terminalVelocity = -17.0f;
        ObjGrassCarry_UpdatePos(this);
        ObjGrassCarry_UpdateBgCheckInfo(this, play);
        this->actor.gravity = -3.2f;
    } else {
        Vec3f pos;
        s32 bgId;

        pos.x = this->actor.world.pos.x;
        pos.y = this->actor.world.pos.y + 20.0f;
        pos.z = this->actor.world.pos.z;
        this->actor.floorHeight =
            BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId, &this->actor, &pos);
    }
}
