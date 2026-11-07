// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_Update(Actor* thisx, PlayState* play) {
    static Vec3f sVelocity = { 0.0f, 0.0f, 0.0f };
    static Vec3f sAccel = { 0.0f, 0.1f, 0.0f };
    EnHonotrap* this = (EnHonotrap*)thisx;

    if (this->timer > 0) {
        this->timer--;
    }
    if ((this->actor.child != NULL) && (this->actor.child->update == NULL)) {
        this->actor.child = NULL;
    }
    this->actionFunc(this, play);
    if (this->collider.tris.base.acFlags & AC_HIT) {
        EffectSsBomb2_SpawnLayered(play, &this->actor.world.pos, &sVelocity, &sAccel, 15, 8);
        Actor_Kill(&this->actor);
        return;
    }
    if (this->eyeState < HONOTRAP_EYE_SHUT) {
        this->collider.tris.base.acFlags &= ~AC_HIT;
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.tris.base);
    }
}
