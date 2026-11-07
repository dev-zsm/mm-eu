// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B39FA8(ObjSnowball2* this, PlayState* play) {
    s32 pad;
    Vec3f sp30;
    s32 bgId;

    ref_func_80B39B28(this, play);

    if (this->unk_1AC > 0) {
        this->unk_1AC--;
        ref_func_80B38EFC(this, play);
    }

    if (Actor_HasNoParent(&this->actor, play)) {
        this->actor.room = play->roomCtx.curRoom.num;
        this->actor.speed *= 3.8f;
        this->actor.velocity.y *= 0.4f;
        this->actor.gravity = -2.8f;
        Actor_MoveWithGravity(&this->actor);
        Actor_UpdateBgCheckInfo(play, &this->actor, 15.0f, 15.0f, 0.0f,
                                UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_40);
        ref_func_80B3A0D8(this);
    } else {
        sp30.x = this->actor.world.pos.x;
        sp30.y = this->actor.world.pos.y + 20.0f;
        sp30.z = this->actor.world.pos.z;
        this->actor.floorHeight =
            BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId, &this->actor, &sp30);
    }
}
