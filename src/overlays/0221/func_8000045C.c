// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_en_fire.h"

void EffectSsEnFire_Update(PlayState* play, u32 index, EffectSs* this) {
    this->rScroll++;

    if (this->actor != NULL) {
        if (this->actor->colorFilterTimer >= 22) {
            this->life++;
        }
        if (this->actor->update != NULL) {
            Math_SmoothStepToS(&this->rScale, this->rScaleMax, 1, this->rScaleMax >> 3, 0);

            if (this->rBodyPart <= BODYPART_NONE) {
                Matrix_Translate(this->actor->world.pos.x, this->actor->world.pos.y, this->actor->world.pos.z,
                                 MTXMODE_NEW);
                Matrix_RotateYS(this->rYaw + this->actor->shape.rot.y, MTXMODE_APPLY);
                Matrix_RotateXS(this->rPitch + this->actor->shape.rot.x, MTXMODE_APPLY);
                Matrix_MultVec3f(&this->vec, &this->pos);
            } else if (this->rFlags & ENFIRE_FLAGS_BODYPART_POS_VEC3S) {
                this->pos.x = ((FireActorS*)this->actor)->firePos[this->rBodyPart].x;
                this->pos.y = ((FireActorS*)this->actor)->firePos[this->rBodyPart].y;
                this->pos.z = ((FireActorS*)this->actor)->firePos[this->rBodyPart].z;
            } else {
                this->pos.x = ((FireActorF*)this->actor)->firePos[this->rBodyPart].x;
                this->pos.y = ((FireActorF*)this->actor)->firePos[this->rBodyPart].y;
                this->pos.z = ((FireActorF*)this->actor)->firePos[this->rBodyPart].z;
            }
        } else if (this->rReg6 != 0) {
            this->life = 0;
        } else {
            this->actor = NULL;
        }
    }
}
