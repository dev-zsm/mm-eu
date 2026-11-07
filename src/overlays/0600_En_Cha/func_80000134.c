// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_cha.h"

void EnCha_Idle(EnCha* this, PlayState* play) {
    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_60_04)) {
        Actor_PlaySfx(&this->actor, NA_SE_EV_DOOR_BELL);
        CLEAR_WEEKEVENTREG(WEEKEVENTREG_60_04);
        this->actor.home.rot.z = 0x7D0;
    }
    if (this->collider.base.acFlags & AC_HIT) {
        Actor_PlaySfx(&this->actor, NA_SE_EV_DOOR_BELL);
        this->actor.home.rot.z = 0x7D0;
        if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_HIT_LAUNDRY_POOL_BELL)) {
            SET_WEEKEVENTREG(WEEKEVENTREG_HIT_LAUNDRY_POOL_BELL);
            this->actionFunc = EnCha_Ring;
        }
    }
    this->actor.home.rot.x += this->actor.home.rot.z;
    this->actor.home.rot.z -= TRUNCF_BINANG(this->actor.home.rot.x * 0.1f);
    this->actor.home.rot.z *= 0.96f;
}
