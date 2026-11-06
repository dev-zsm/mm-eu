// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

void ObjChan_PotAction(ObjChan* this, PlayState* play) {
    s32 potBreaks;
    s32 phi_v1;

    potBreaks = false;
    if ((this->collider.base.acFlags & AC_HIT) && (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0x4004000)) {
        potBreaks = true;
    }
    if (this->stateFlags & OBJCHAN_STATE_ON_FIRE) {
        Math_StepToF(&this->flameSize, 1.0f, 0.05f);
    } else if (this->stateFlags & OBJCHAN_STATE_FIRE_DELAY) {
        this->fireDelayFrames--;
        if (this->fireDelayFrames <= 0) {
            this->stateFlags |= OBJCHAN_STATE_ON_FIRE;
        }
    }
    if (potBreaks) {
        ObjChan_CreateSmashEffects(this, play);
        ((ObjChan*)this->actor.parent)->pots[this->myPotIndex] = NULL;
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_CHANDELIER_BROKEN);
        ref_func_80BB9A1C((ObjChan*)this->actor.parent, 40.0f);
        if (this->myPotIndex == 4) {
            if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_37_10)) {
                SET_WEEKEVENTREG(WEEKEVENTREG_37_10);
                Actor_SpawnAsChildAndCutscene(&play->actorCtx, play, ACTOR_EN_MM, this->actor.world.pos.x,
                                              this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, 0x8000,
                                              this->actor.csId, this->actor.halfDaysBits, NULL);
            }
        }
        Actor_Kill(&this->actor);
    }
}
