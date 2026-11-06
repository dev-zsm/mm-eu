// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1CC0C(ObjFlowerpot* this, PlayState* play) {
    s32 pad;

    ref_func_80A1C62C(this, play);

    if (Actor_HasNoParent(&this->actor, play)) {
        this->actor.room = play->roomCtx.curRoom.num;
        if (fabsf(this->actor.speed) < 0.1f) {
            ref_func_80A1C818(this);
            Player_PlaySfx(GET_PLAYER(play), NA_SE_PL_PUT_DOWN_POT);
            this->collider.base.ocFlags1 &= ~OC1_TYPE_PLAYER;
        } else {
            Actor_MoveWithGravity(&this->actor);
            ref_func_80A1CD10(this);
        }
        ref_func_80A1C5E8(this, play);
    } else {
        Vec3f sp30;
        s32 bgId;

        sp30.x = this->actor.world.pos.x;
        sp30.y = this->actor.world.pos.y + 20.0f;
        sp30.z = this->actor.world.pos.z;
        this->actor.floorHeight =
            BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId, &this->actor, &sp30);
    }
}
