// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5D9C8(EnKusa2* this, PlayState* play) {
    s32 pad;
    Vec3f sp30;
    s32 bgId;

    ref_D_80A5EAF4.x += 11000;
    ref_D_80A5EAF4.y += 17000;
    ref_D_80A5EAF4.z += 9000;

    this->actor.scale.x = (Math_SinS(ref_D_80A5EAF4.x) * 0.020000001f) + 0.4f;
    this->actor.scale.y = (Math_SinS(ref_D_80A5EAF4.y) * 0.020000001f) + 0.4f;
    this->actor.scale.z = (Math_SinS(ref_D_80A5EAF4.z) * 0.020000001f) + 0.4f;

    ref_D_80A5EB04.x += 18000;
    ref_D_80A5EB04.y += 17000;
    ref_D_80A5EB04.z += 16000;

    ref_D_80A5EAFC.x = Math_SinS(ref_D_80A5EB04.x) * 1000.0f;
    ref_D_80A5EAFC.y = Math_SinS(ref_D_80A5EB04.y) * 1000.0f;
    ref_D_80A5EAFC.z = Math_SinS(ref_D_80A5EB04.z) * 1000.0f;

    if (Actor_HasNoParent(&this->actor, play)) {
        this->actor.room = play->roomCtx.curRoom.num;
        this->actor.colChkInfo.mass = 80;
        this->actor.home.rot.y = this->actor.world.rot.y;
        this->actor.velocity.y = 12.5f;
        this->actor.speed += 3.0f;
        Actor_MoveWithGravity(&this->actor);
        ref_func_80A5BAFC(this, play);
        ref_func_80A5CD0C(this);
        this->unk_1C8 = 30;
        ref_func_80A5DC70(this);
    } else {
        sp30.x = this->actor.world.pos.x;
        sp30.y = this->actor.world.pos.y + 20.0f;
        sp30.z = this->actor.world.pos.z;

        if (Rand_Next() < 0xFFFFFFF) {
            ref_func_80A5CD0C(this);
        }

        this->unk_1D0--;
        if (this->unk_1D0 <= 0) {
            Actor_PlaySfx(&this->actor, NA_SE_EN_KUSAMUSHI_VIBE);
            this->unk_1D0 = (Rand_Next() >> 0x1D) + 14;
        }

        this->actor.floorHeight =
            BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId, &this->actor, &sp30);
    }
}
